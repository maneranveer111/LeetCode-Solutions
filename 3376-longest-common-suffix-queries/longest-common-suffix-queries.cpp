class Solution {
public:
    struct TrieNode {
        int children[26];
        int bestIdx; // index of best wordsContainer string through this node
        TrieNode(int best) : bestIdx(best) {
            fill(children, children + 26, -1);
        }
    };

    vector<TrieNode> trie;

    // Returns true if idx is a better candidate than cur given lengths
    bool isBetter(int idx, int cur, vector<string>& words) {
        if (cur == -1) return true;
        int lenIdx = words[idx].size();
        int lenCur = words[cur].size();
        return lenIdx < lenCur; // earlier index already wins on tie due to insertion order
    }

    void insert(const string& word, int idx, vector<string>& words) {
        int node = 0;
        // Update root with this candidate
        if (isBetter(idx, trie[0].bestIdx, words))
            trie[0].bestIdx = idx;

        for (char c : word) {
            int ch = c - 'a';
            if (trie[node].children[ch] == -1) {
                trie[node].children[ch] = trie.size();
                trie.emplace_back(idx); // new node: set best to current idx
            } else {
                int next = trie[node].children[ch];
                if (isBetter(idx, trie[next].bestIdx, words))
                    trie[next].bestIdx = idx;
            }
            node = trie[node].children[ch];
        }
    }

    int query(const string& word) {
        int node = 0;
        for (char c : word) {
            int ch = c - 'a';
            if (trie[node].children[ch] == -1)
                break;
            node = trie[node].children[ch];
        }
        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Initialize trie with a root node (bestIdx = -1 placeholder)
        trie.emplace_back(-1);

        // Find the global best (shortest, earliest) for root node
        int globalBest = 0;
        for (int i = 1; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].size() < wordsContainer[globalBest].size())
                globalBest = i;
        }
        trie[0].bestIdx = globalBest;

        // Insert reversed words
        for (int i = 0; i < wordsContainer.size(); i++) {
            string rev = wordsContainer[i];
            reverse(rev.begin(), rev.end());
            insert(rev, i, wordsContainer);
        }

        // Answer queries
        vector<int> ans;
        for (auto& q : wordsQuery) {
            string rev = q;
            reverse(rev.begin(), rev.end());
            ans.push_back(query(rev));
        }
        return ans;
    }
};