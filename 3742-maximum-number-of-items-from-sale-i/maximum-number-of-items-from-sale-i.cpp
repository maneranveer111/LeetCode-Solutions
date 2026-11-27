class Solution {
public:
    int n;
    vector<int> freeCnt;
    vector<int> cost;
    vector<vector<long long>> memo;

    long long helper(int idx, int budget, vector<vector<int>>& items) {
        if(idx == n || budget == 0)
            return 0;

        if(memo[idx][budget] != -1)
            return memo[idx][budget];

        long long skip = helper(idx + 1, budget, items);
        long long take = 0;
        if(budget >= cost[idx]) {
            take = (long long)(1 + freeCnt[idx]) + 
                    helper(idx + 1, budget - cost[idx], items);
        }

        return memo[idx][budget] = max(skip, take);
    }
    
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        cost.resize(n);
        freeCnt.resize(n, 0);

        for(int i = 0; i < n; i++) {
            cost[i] = items[i][1];
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0)
                    freeCnt[i]++;
            }
        }

        int minCst = *min_element(cost.begin(), cost.end());

        memo.assign(n, vector<long long>(budget + 1, -1));

        long long ans = 0;
        for(int i = 0; i <= budget; i++) {
            long long from = helper(0, i, items);
            long long buy = (long long)(budget - i) / minCst;
            ans = max(ans, buy + from);
        }
        
        return ans;
    }
};