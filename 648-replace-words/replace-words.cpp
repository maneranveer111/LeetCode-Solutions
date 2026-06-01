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

    string replace(Trie* root, string word) {
        Trie* curr = root;
        string ans = "";
        for(char ch : word) {
            if(!curr->child[ch - 'a'])
                return word;
            ans += ch;
            curr = curr->child[ch - 'a'];
            if(curr->isEnd)
                return ans;
        }

        return (curr->isEnd) ? ans : word;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Trie();
        for(int i = 0; i < dictionary.size(); i++) {
            insert(root, dictionary[i]);
        }

        string ans = "", curr = "";
        int i = 0;

        while(i < sentence.size()) {
            while(i < sentence.size() && sentence[i] == ' ')
                i++;
            while(i < sentence.size() && sentence[i] != ' ') {
                curr += sentence[i];
                i++;
            }

            string rt = replace(root, curr);
            if(!rt.empty()) {
                if(!ans.empty()) 
                    ans += " " + rt;
                else 
                    ans += rt;
            }

            curr = "";
        }
        
        return ans;
    }
};
