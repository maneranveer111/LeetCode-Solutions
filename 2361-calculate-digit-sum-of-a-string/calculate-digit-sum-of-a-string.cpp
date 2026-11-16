class Solution {
public:
    string helper(const string& s, int k) {
        string ans = "";
        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (cnt == k) {
                ans += to_string(sum);
                sum = 0;
                cnt = 0;
            }
            cnt++;
            sum += (s[i] - '0');
        }

        ans += to_string(sum);  
        return ans;
    }

    string digitSum(string s, int k) {
        while ((int)s.size() > k) {
            s = helper(s, k);
        }
        return s;
    }
};