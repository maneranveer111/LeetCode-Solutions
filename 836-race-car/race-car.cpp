class Solution {
public:
    int racecar(int target) {
        queue<pair<long long, long long>> q;
        set<pair<long long, long long>> vis;

        q.push({0, 1});
        vis.insert({0, 1});
        long long steps = 0;

        while(!q.empty()) {
            long long sz = q.size();

            for(int i = 0; i < sz; i++) {
                auto [pos, speed] = q.front();
                q.pop();

                if(pos == target)
                    return steps; 

                long long npacc = pos + speed;
                long long nspp = speed * 2;

                if(npacc >= 0 && npacc <= 2 * target && !vis.count({npacc, nspp})) {
                    vis.insert({npacc, nspp});
                    q.push({npacc, nspp});
                }

                if(speed >= 0) {
                    if(!vis.count({pos, -1})) {
                        vis.insert({pos, -1});
                        q.push({pos, -1});
                    }
                }
                else {
                    if(!vis.count({pos, 1})) {
                        vis.insert({pos, 1});
                        q.push({pos, 1});
                    }
                }
            }

            steps++;
        }    

        return -1;
    }
};