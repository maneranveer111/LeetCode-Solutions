class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        int currLev = 0;
        queue<int> q;
        q.push(id);
        vector<int> fri;
        vector<int> vis(n, 0);
        vis[id] = 1;

        while(!q.empty()) {
            int sz = q.size();
            if(currLev == level) {
                while(!q.empty()) {
                    fri.push_back(q.front());
                    q.pop();
                }
                break;
            }

            for(int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();

                for(auto nei : friends[node]) {
                    if(!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }

            currLev++;
        }


        unordered_map<string, int> freq;
        for(int fid : fri) {
            for(string s : watchedVideos[fid]) {
                freq[s]++;
            }
        }

        vector<pair<int, string>> vec;
        for(auto [s, feq] : freq) {
            vec.push_back({feq, s});
        }

        sort(vec.begin(), vec.end());

        vector<string> ans;

        for(auto v : vec) {
            ans.push_back(v.second);
        }

        return ans;
    }
};