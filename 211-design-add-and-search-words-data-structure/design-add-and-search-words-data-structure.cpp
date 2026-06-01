struct Trie{
    Trie* child[26];
    bool isEnd;

    Trie() : isEnd(false) {
        fill(child, child + 26, nullptr);
    }
};

void insert(Trie* root, string& word) {
    Trie* curr = root;
    for(char ch : word) {
        if(curr->child[ch - 'a']) {
            curr->child[ch - 'a'] = new Trie();
        }
        curr = curr->child[ch - 'a'];
    }

    curr->isEnd = true;
} 



class WordDictionary {
    Trie* root;

    bool find(Trie* curr, string word, int idx) {
        if(idx >= word.size())
            return curr->isEnd;
        char ch = word[idx];
        
        if(ch == '.') {
            for(int i = 0; i < 26; i++) {
                if(curr->child[i] && find(curr->child[i], word, idx + 1))
                    return true;
            }

            return false;
        }
        else {
            if(!curr->child[ch - 'a'])
                return false;
            
            return find(curr->child[ch - 'a'], word, idx + 1);
        }
        
    }

public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(char ch : word) {
            if(!curr->child[ch - 'a']) {
                curr->child[ch - 'a'] = new Trie();
            }
            curr = curr->child[ch - 'a'];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        return find(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
