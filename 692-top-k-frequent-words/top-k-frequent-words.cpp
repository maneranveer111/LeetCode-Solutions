struct Trie{
    Trie* child[26];
    bool isEnd;
    int freq;

    Trie() : isEnd(false), freq(0) {
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
        curr->freq++;
    }
    
    void dfs(Trie* node, string& curr, vector<pair<string, int>>& store) {
        if(node->isEnd) {
            store.push_back({curr, node->freq});
        }

        for(int i = 0; i < 26; i++) {
            if(node->child[i]) {
                curr.push_back((char)(i + 'a'));
                dfs(node->child[i], curr, store);
                curr.pop_back();
            }
        }
    }

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        root = new Trie();
        for(int i = 0; i < words.size(); i++) {
            insert(root, words[i]);
        }
        
        vector<pair<string, int>> store;
        string curr = "";
        dfs(root, curr, store);
        sort(store.begin(), store.end(), [](auto& a, auto& b) {
            if(a.second == b.second) 
                return a.first < b.first;
            return a.second > b.second;
        });

        vector<string> ans;
        for(int i = 0; i < store.size(); i++) {
            if(k > 0) {
                ans.push_back(store[i].first);
                k--;
            }
            else if(k == 0)
                break;
        }

        return ans;
    }
};