class Trie {
public:
    Trie *children[26];
    bool isEnd;

    Trie() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;   
    }
    

    void insert(string word) {
        Trie* curr = this;
        for(char c : word) {
            if(!curr->children[c - 'a']) {
                Trie* newNode = new Trie();
                curr->children[c - 'a'] = newNode;
            }

            curr = curr->children[c - 'a'];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for(char ch : word) {
            if(!curr->children[ch - 'a'])
                return false;
            
            curr = curr->children[ch - 'a'];
        }   

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
       Trie* curr = this;
        for(char ch : prefix) {
            if(!curr->children[ch - 'a'])
                return false;
            
            curr = curr->children[ch - 'a'];
        }   

        return  true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */