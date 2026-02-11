class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        sort(strNums.begin(), strNums.end(), [](const string& x, const string& y) {
            return x + y > y + x;
        });

        string ans = "";

        for(string st : strNums) {
            ans += st;
        }
        
        return (ans[0] == '0') ? "0" : ans;
    }
};