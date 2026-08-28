class MagicDictionary {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode* root;

    MagicDictionary() {
        root = new TrieNode();
    }

    void buildDict(vector<string> dictionary) {
        for (const string& word : dictionary) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->isEnd = true;
        }
    }

    bool search(string searchWord) {
        return dfs(root, searchWord, 0, false);
    }

private:
    bool dfs(TrieNode* node, const string& word, int i, bool used) {
        if (!node) return false;

        if (i == word.size())
            return used && node->isEnd;

        int idx = word[i] - 'a';

        for (int c = 0; c < 26; c++) {
            if (!node->children[c]) continue;

            if (c == idx) {
                if (dfs(node->children[c], word, i + 1, used))
                    return true;
            } else if (!used) {
                if (dfs(node->children[c], word, i + 1, true))
                    return true;
            }
        }

        return false;
    }
};