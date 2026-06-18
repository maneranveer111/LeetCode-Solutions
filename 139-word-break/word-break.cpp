struct Trie{
    Trie *child[26];
    bool isEnd;

    Trie() : isEnd(false) {
        fill(child, child + 26, nullptr);
    }
};

class Solution {
public:
    vector<int> memo;

    Trie* root;
    void insert(Trie* root, string& word) {
        Trie* curr = root;

        for(char ch : word) {
            if(!curr->child[ch - 'a'])
                curr->child[ch - 'a'] = new Trie();
            
            curr = curr->child[ch - 'a'];
        }

        curr->isEnd = true;
    }        

    bool isPresent(Trie* root, string word) {
        Trie* curr = root;

        for(char ch : word) {
            if(!curr->child[ch - 'a'])
                return false;
            
            curr = curr->child[ch - 'a'];
        }

        if(curr->isEnd)
            return true;

        return false;
    }

    bool helper(string& s, int idx) {
        if(idx == s.size())
            return true;
        if(memo[idx] != -1)
            return memo[idx];

        for(int i = idx; i < s.size(); i++) {
            if(isPresent(root, s.substr(idx, i - idx + 1))) {
                bool callnext = helper(s, i + 1);
                if(callnext)
                    return true;
            }
        }

        return memo[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Trie();
        memo.assign(s.size() + 1, -1);
        
        for(string word : wordDict) {
            insert(root, word);
        }
        
        return helper(s, 0);
    }
};