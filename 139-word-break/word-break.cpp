// struct Trie{
//     Trie *child[26];
//     bool isEnd;

//     Trie() : isEnd(false) {
//         fill(child, child + 26, nullptr);
//     }
// };

// class Solution {
// public:
//     vector<int> memo;

//     Trie* root;
//     void insert(Trie* root, string& word) {
//         Trie* curr = root;

//         for(char ch : word) {
//             if(!curr->child[ch - 'a'])
//                 curr->child[ch - 'a'] = new Trie();
            
//             curr = curr->child[ch - 'a'];
//         }

//         curr->isEnd = true;
//     }        

//     bool isPresent(Trie* root, string word) {
//         Trie* curr = root;

//         for(char ch : word) {
//             if(!curr->child[ch - 'a'])
//                 return false;
            
//             curr = curr->child[ch - 'a'];
//         }

//         if(curr->isEnd)
//             return true;

//         return false;
//     }

//     bool helper(string& s, int idx) {
//         if(idx == s.size())
//             return true;
//         if(memo[idx] != -1)
//             return memo[idx];

//         for(int i = idx; i < s.size(); i++) {
//             if(isPresent(root, s.substr(idx, i - idx + 1))) {
//                 bool callnext = helper(s, i + 1);
//                 if(callnext)
//                     return true;
//             }
//         }

//         return memo[idx] = false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         root = new Trie();
//         memo.assign(s.size() + 1, -1);
        
//         for(string word : wordDict) {
//             insert(root, word);
//         }
        
//         return helper(s, 0);
//     }
// };

struct Trie {
    Trie* child[26];
    bool isEnd;

    Trie() : isEnd(false) {
        fill(child, child + 26, nullptr);
    }
};

class Solution {
public:
    Trie* root;

    void insert(Trie* root, string& word) {
        Trie* curr = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if (!curr->child[ch])
                curr->child[ch] = new Trie();
            curr = curr->child[ch];
        }
        curr->isEnd = true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        for (string& word : wordDict)
            insert(root, word);

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            Trie* curr = root;
            for (int j = i - 1; j >= 0; j--) {
                int ch = s[j] - 'a';
                if (!curr->child[ch]) break;
                curr = curr->child[ch];
                if (curr->isEnd && dp[j])
                    dp[i] = true;
            }
        }

        return dp[n];
    }
};