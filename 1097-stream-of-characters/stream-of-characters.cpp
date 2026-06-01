struct Trie{
    Trie* child[26];
    bool isEnd;

    Trie() : isEnd(false) {
        fill(child, child + 26, nullptr);
    } 
};

class StreamChecker {
    Trie* root;
    string store;

    void insert(Trie* root, string& word) {
        Trie* curr = root;
        reverse(word.begin(), word.end());

        for(char ch : word) {
            if(!curr->child[ch - 'a']) {
                curr->child[ch - 'a'] = new Trie();
            }
            curr = curr->child[ch - 'a'];
        }

        curr->isEnd = true;
    }

public:

    StreamChecker(vector<string>& words) {
        root = new Trie();
        for(string& s : words) {
            insert(root, s);
        }
    }
    
    bool query(char letter) {
        store += letter;
        Trie* curr = root;
        for(int i = store.size() - 1; i >= 0; i--) {
            char ch = store[i];
            if(!curr->child[ch - 'a'])
                return false;
            
            curr = curr->child[ch - 'a'];
            if(curr->isEnd)
                return true;
        }

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */