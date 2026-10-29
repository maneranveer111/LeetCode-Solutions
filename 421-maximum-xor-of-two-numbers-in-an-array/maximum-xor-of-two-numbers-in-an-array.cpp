class Solution {
public:
    struct Node {
        Node* links[2] = {nullptr, nullptr};

        bool containsKey(int bit) {
            return links[bit] != nullptr;
        }

        Node* getKey(int bit) {
            return links[bit];
        }

        void putKey(int bit, Node* node) {
            links[bit] = node;
        }
    };

    class Trie {
    private:
        Node* root;

    public:
        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (!node->containsKey(bit)) {
                    node->putKey(bit, new Node());
                }

                node = node->getKey(bit);
            }
        }

        int findMax(int num) {
            Node* node = root;
            int maxNum = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (node->containsKey(1 - bit)) {
                    maxNum |= (1 << i);
                    node = node->getKey(1 - bit);
                } else {
                    node = node->getKey(bit);
                }
            }

            return maxNum;
        }
    };

    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }

        int ans = 0;
        for (int num : nums) {
            ans = max(ans, trie.findMax(num));
        }

        return ans;
    }
};