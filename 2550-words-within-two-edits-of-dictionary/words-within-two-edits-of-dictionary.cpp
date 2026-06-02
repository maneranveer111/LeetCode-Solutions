struct Trie{
    Trie* child[26];
    bool isEnd;

    Trie() : isEnd(false) {
        fill(child, child + 26, nullptr);
    }
};

class Solution {
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

    bool dfs(Trie* node, string& word, int change, int idx) {
        if(change > 2)
            return false;
        
        if(idx == word.size())
            return node->isEnd;

        for(int i = 0; i < 26; i++) {
            if(node->child[i]) {
                if(word[idx] != (char)('a' + i)) {
                    if(dfs(node->child[i], word, change + 1, idx + 1))
                        return true;
                }
                else {
                    if(dfs(node->child[i], word, change, idx + 1))
                        return true;
                }
                
            }
        }

        return node->isEnd;
    }

public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        root = new Trie();
        for(string word : dictionary) {
            insert(root, word);
        }
        vector<string> ans;
        for(string word : queries) {
            if(dfs(root, word, 0, 0))
                ans.push_back(word);
        }

        return ans;
    }
};