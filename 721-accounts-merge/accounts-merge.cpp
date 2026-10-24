class Solution {
public:
    class DisJointSet {
        vector<int> parent, size;
        public:
            DisJointSet(int n) {
                size.assign(n, 1);
                parent.assign(n, 0);
                for(int i = 0; i < n; i++)
                    parent[i] = i;
            }

            int findUltParent(int node) {
                if(parent[node] == node)
                    return node;
                return parent[node] = findUltParent(parent[node]);
            }

            void unionBySize(int u, int v) {
                int ultPar_u = findUltParent(u);
                int ultPar_v = findUltParent(v);

                if(ultPar_v == ultPar_u)
                    return;
                
                if(size[ultPar_u] < size[ultPar_v]) {
                    parent[ultPar_u] = ultPar_v;
                    size[ultPar_v] += size[ultPar_u];
                }
                else{
                    parent[ultPar_v] = ultPar_u;
                    size[ultPar_u] += size[ultPar_v];
                }
            }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJointSet djs(n);

        unordered_map<string, int> mailToNode;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(mailToNode.count(mail)) {
                    int k = mailToNode[mail];
                    djs.unionBySize(i, k);
                }
                else 
                    mailToNode[mail] = i;
            }
        }

        vector<vector<string>> mergeMail(n);

        for(auto& [x, y] : mailToNode) {
            int ultPar_y = djs.findUltParent(y);
            mergeMail[ultPar_y].push_back(x);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(mergeMail[i].size() == 0)
                continue;
            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            for(string str : mergeMail[i])
                tmp.push_back(str);
            sort(tmp.begin() + 1, tmp.end());

            ans.push_back(tmp);
        }

        return ans;
    }
};