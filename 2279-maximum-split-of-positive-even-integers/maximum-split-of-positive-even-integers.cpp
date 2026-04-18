class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 != 0) 
            return  {};
        
        vector<long long> ans;
        long long curr = 2;

        while(curr <= finalSum) {
            ans.push_back(curr);
            finalSum -= curr;
            curr += 2;
        }

        ans.back() += finalSum;

        return ans;
    }
};