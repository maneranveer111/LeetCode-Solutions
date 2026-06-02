struct Trie{
    Trie* child[26];
    bool isEnd;
    vector<string> store;
    int cnt;

    Trie() : isEnd(false), cnt(0) {
        fill(child, child + 26, nullptr);
    }
};

class Solution {
    Trie* root;
    void insert(Trie* root, string& word) {
        Trie* curr = root;
        for(char ch : word) {
            if(!curr->child[ch - 'a']) {
                curr->child[ch - 'a'] = new Trie();
            }

            if(curr->child[ch - 'a']->cnt < 3) {
                curr->child[ch - 'a']->store.push_back(word);
                curr->child[ch - 'a']->cnt++;
            }

            curr = curr->child[ch - 'a'];
        }

        curr->isEnd = true;
    }

    void traverse(Trie* root, string& word, vector<vector<string>>& ans) {
        Trie* curr = root;
        for(char ch : word) {
            if (!curr->child[ch - 'a']) {
                while (ans.size() < word.size())
                    ans.push_back({});
                return;
            }
            ans.push_back(curr->child[ch - 'a']->store);
            curr = curr->child[ch - 'a'];
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        root = new Trie();
        for(string word : products) {
            insert(root, word);
        }
        vector<vector<string>> ans;
        traverse(root, searchWord, ans);

        return ans;
    }
};
// Line 35: Char 50: runtime error: member access within null pointer of type 'Trie' (solution.cpp)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:44:50