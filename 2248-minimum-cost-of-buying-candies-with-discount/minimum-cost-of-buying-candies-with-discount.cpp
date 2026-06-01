class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), [](int a, int b){
            return a > b;
        });

        int ans = 0, prev = 0, curr = 0;

        for(int i = 0; i < cost.size(); i++) {
            if(prev + 2 == curr) {
                curr++;
                prev = curr;
                continue;
            }
            ans += cost[i];
            curr++;
        }
        
        return ans;
    }
};