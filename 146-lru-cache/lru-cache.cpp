class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int cap;
    
    void addNodetoHead(Node* node) {
        Node* headnxt = head->next;
        node->next = headnxt;
        headnxt->prev = node;
        node->prev = head;
        head->next = node;
    }

    void deleteNode(Node* node) {
        Node* prevnode = node->prev;
        Node* nxtnode = node->next; 
        prevnode->next = nxtnode;
        nxtnode->prev = prevnode;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        int ans = mp[key]->val;

        deleteNode(mp[key]);
        addNodetoHead(mp[key]);

        return ans; 
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            mp[key]->val = value;
            deleteNode(mp[key]);
            addNodetoHead(mp[key]);
        }
        else if(mp.size() < cap) {
            Node* node = new Node(key, value);
            mp[key] = node;
            addNodetoHead(mp[key]);
        }
        else {
            Node* node = new Node(key, value);
            mp[key] = node;
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
            addNodetoHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */