class Solution {
public:

    bool isPrime(int x) {
        if(x < 2) return false;

        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {

            int x = nums[i];

            for(int p = 2; p * p <= x; p++) {

                if(x % p == 0) {

                    mp[p].push_back(i);

                    while(x % p == 0)
                        x /= p;
                }
            }

            if(x > 1)
                mp[x].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        unordered_set<int> usedPrime;

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                int i = q.front();
                q.pop();

                if(i == n - 1)
                    return steps;

                if(i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                if(i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }
                
                int val = nums[i];

                if(isPrime(val) && !usedPrime.count(val)) {

                    for(auto idx : mp[val]) {

                        if(!vis[idx]) {
                            vis[idx] = 1;
                            q.push(idx);
                        }
                    }

                    usedPrime.insert(val);
                }
            }

            steps++;
        }

        return -1;
    }
};