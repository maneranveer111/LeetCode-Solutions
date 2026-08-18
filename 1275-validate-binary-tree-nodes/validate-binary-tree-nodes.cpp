class Solution {
public:
    class DisJointSet {
        public:
        vector<int> parent;

            DisJointSet(int n) {
                parent.resize(n);
                for(int i = 0; i < n; i++)
                    parent[i] = i;
            }

            int findUltParent(int node) {
                if(parent[node] == node)
                    return node;
                
                return parent[node] = findUltParent(parent[node]);
            }
    };

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisJointSet djs(n);

        for(int i = 0; i < n; i++) {
            int lft = leftChild[i];
            int rht = rightChild[i];

            if(lft != -1) {
                if(djs.findUltParent(lft) != lft)
                    return false;
                
                if(djs.findUltParent(i) == lft)
                    return false;
                
                djs.parent[lft] = i;
            }

            if(rht != -1) {
                if(djs.findUltParent(rht) != rht)
                    return false;

                if(djs.findUltParent(i) == rht)
                    return false;

                djs.parent[rht] = i;
            }
        }    

        int root = -1;
        for(int i = 0; i < n; i++) {
            if(djs.findUltParent(i) == i) {
                if(root != -1)
                    return false;
                root = i;
            }
        }

        return true;
    }
};