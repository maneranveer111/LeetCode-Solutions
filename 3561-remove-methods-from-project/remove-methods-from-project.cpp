class Solution {
public:
    unordered_set<int> suspicious; 
    vector<int> vis,  ans;

    void dfs(int k, vector<vector<int>>& edges) {
        if(vis[k] != -1)
            return;
        vis[k] = 1;

        suspicious.insert(k);

        for(auto it : edges[k]) {
            if(vis[it] == -1) {
                dfs(it, edges);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vis.assign(n, -1);

        for(auto it : invocations) {
            edges[it[0]].push_back(it[1]);
        }    
         
        dfs(k, edges);
        
        bool flag = false;

        for(auto it : invocations) {
            if(!suspicious.count(it[0]) && suspicious.count(it[1]))
                flag = true;
        }    

        if(flag)
            for(int i = 0; i < n; i++)  
                ans.push_back(i);

        if(flag)
            return ans;

        for(int i = 0; i < n; i++) {
            if(!suspicious.count(i))  
                ans.push_back(i);
        }

        return ans;
    }
};

