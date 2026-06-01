struct Trie{
    Trie* child[26];
    bool isEnd;

    Trie() : isEnd(false) {
        fill(child, child + 26, nullptr);
    }
};

class Solution {
    Trie* root;
    void insert(Trie* root, string word) {
        Trie* curr = root;

        for(char ch : word) {
            if(!curr->child[ch - 'a'])
                curr->child[ch - 'a'] = new Trie();
         
            curr = curr->child[ch - 'a'];
        }

        curr->isEnd = true;
    }
    
    bool isPrefix(Trie* root, string pre) {
        Trie* curr = root;

        for(char ch : pre) {
            if(!curr->child[ch - 'a'])
                return false;
            curr = curr->child[ch - 'a'];
        }
        
        if(curr->isEnd)
            return true;
        
        return false;
    }

public:
    string longestWord(vector<string>& words) {
        root = new Trie();

        for(string word : words) {
            insert(root, word);
        }

        string ans = "";

        for(string word : words) {
            int all = 0;
            for(int i = 0; i < word.size(); i++) {
                if(isPrefix(root, word.substr(0, i + 1))) {
                    all++;
                }
            }

            if(all < word.size())
                continue;

            if(ans.empty() || word.size() > ans.size())
                ans = word;
            else if(ans.size() == word.size()) {
                ans = (ans < word) ? ans : word;
            }
        }

        return ans;
    }
};