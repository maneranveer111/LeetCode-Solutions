class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int ans = 0;
        queue<int> q;
        vector<int> vis(n, 0);
        vector<int> got(n, 0);

        for(int i : initialBoxes) {
            got[i] = 1;
            if(status[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }

        while(!q.empty()) {
            int box = q.front();
            q.pop();

            ans += candies[box];

            for(auto nei : keys[box]) {
                status[nei] = 1;
                if(got[nei] && !vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }

            for(auto nei : containedBoxes[box]) {
                got[nei] = 1;
                if(!vis[nei] && status[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }

        return ans;
    }
};