class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> adj;
        for (auto& vec : reservedSeats) {
            adj[vec[0]].push_back(vec[1]);
        }

        unordered_map<int, vector<int>> mp;
        mp[2] = {1};
        mp[3] = {1};
        mp[4] = {1, 2};
        mp[5] = {1, 2};
        mp[6] = {2, 3};
        mp[7] = {2, 3};
        mp[8] = {3};
        mp[9] = {3};

        int ans = 2 * (n - (int)adj.size());

        for (auto& [row, vec] : adj) {
            int g1 = 1, g2 = 1, g3 = 1;

            for (int seat : vec) {
                if (mp.find(seat) == mp.end())
                    continue;
                for (auto x : mp[seat]) {
                    if (x == 1 && g1 != 0) g1--;
                    else if (x == 2 && g2 != 0) g2--;
                    else if (x == 3 && g3 != 0) g3--;
                }
            }

            if (g1 && g2 && g3)
                ans += 2;
            else if ((g1 && g2) || (g2 && g3))
                ans += 1;
            else
                ans += g1 + g2 + g3; 
        }

        return ans;
    }
};