class Solution {
public:
    int digSum(int num) {
        string nm = to_string(num);
        int sum = 0;
        for(char ch : nm)
            sum += ch - '0';
        
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<vector<int>> store;

        for(int i = 0; i < nums.size(); i++) {
            int sum = digSum(nums[i]);

            store.push_back({sum, nums[i], i});
        }

        sort(store.begin(), store.end());

        int cnt = 0;
        vector<int> map(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            map[store[i][2]] = i; 
        }

        // int cnt = 0;    
        vector<int> vis(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++) {
            if(vis[i])
                continue;
            vis[i] = 1;
            cnt++;

            int j = i;
            while(!vis[map[j]]) {
                vis[map[j]] = 1;
                j = map[j];
            }
        }

        return nums.size() - cnt;
    }
};