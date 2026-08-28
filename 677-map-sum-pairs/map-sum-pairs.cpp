class MapSum {
public:
    struct Trie {
        unordered_map<char, Trie*> children;
        int val = 0;
    };

    Trie* root;
    unordered_map<string, int> keyVal;

    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        int diff = val - keyVal[key];
        keyVal[key] = val;

        Trie* node = root;
        node->val += diff;

        for(char ch : key) {
            if(!node->children.count(ch)) 
                node->children[ch] = new Trie();
            node = node->children[ch];
            node->val += diff;
        }

    }
    
    int sum(string prefix) {
        Trie* node = root;
        for(char ch : prefix) {
            if(!node->children.count(ch))
                return 0;
            node = node->children[ch];
        }

        return node->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */