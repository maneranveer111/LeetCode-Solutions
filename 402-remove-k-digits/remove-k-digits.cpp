class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k) return "0";
    

        string ans = "";
        
        for(char ch : num) {
            while(!ans.empty() && ans.back() > ch && k > 0) {
                ans.pop_back();
                k--;
            }

            ans += ch;
        }

        while(k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        int start = 0;
        while(start < ans.size() && ans[start] == '0') {
            start++;
        }
        ans = ans.substr(start);

        return (ans.empty()) ? "0" : ans;
    }
};