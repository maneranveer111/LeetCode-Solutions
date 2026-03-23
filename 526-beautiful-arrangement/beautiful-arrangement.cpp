class Solution {
public:
    int ans = 0;
    
    void helper(int idx, vector<bool>& vis) {
        if(idx >= vis.size()) {
            ans++;
            return;
        }

        for(int i = 1; i <= vis.size() - 1; i++) {
            if(vis[i]) continue;

            if(i % idx == 0 || idx % i == 0) {
                vis[i] = true;
                helper(idx + 1, vis);
                vis[i] = false;
            }
        } 
    }

    int countArrangement(int n) {
        vector<bool> vis(n + 1, false);
        helper(1, vis);
        
        return ans;
    }
};