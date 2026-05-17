class Solution {
public:
    bool dfs(vector<int>& arr, vector<int>& vis, int idx) {
        if(idx >= arr.size() || idx < 0)
            return false;
        
        if(vis[idx] == 1)
            return false;

        if(arr[idx] == 0)
            return true;

        vis[idx] = 1;

        bool plus = dfs(arr, vis, idx + arr[idx]);
        if(plus)
            return true;
        bool minus = dfs(arr, vis, idx - arr[idx]);

        return minus;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), -1);
        return dfs(arr, vis, start);    
    }
};