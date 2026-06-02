class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> dec(n, 0), inc(n, 0);
        // if(dec == security && time != 0)
        //     return {};
        dec[0] = 0;
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(security[i] <= security[i - 1])
                cnt++;
            else 
                cnt = 0;
            
            dec[i] = cnt;
        }
        cnt = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(security[i] <= security[i + 1])
                cnt++;
            else 
                cnt = 0;
            
            inc[i] = cnt;
        }
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(dec[i] >= time && inc[i] >= time)
                ans.push_back(i);
        }
        
        return ans;
    }
};