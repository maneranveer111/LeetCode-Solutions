class MagicDictionary {
public:
    vector<string> vec;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        vec = dictionary;
    }
    
    bool search(string searchWord) {
        bool match = false;

        for(string s : vec) {
            if(s.size() != searchWord.size())
                continue;
            else {
                int mismatch = 0;
                for(int i = 0; i < s.size(); i++) {
                    if(s[i] != searchWord[i]) {
                        mismatch++;
                    }
                } 
                
                if(mismatch == 1) {
                    return true;
                }
            }
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */