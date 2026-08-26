class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len = 1e9;
        int cnt = 0, lft = 0;
        int st = -1, en = -1;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '1') cnt++;

            while (cnt > k) {
                if (s[lft] == '1') cnt--;
                lft++;
            }
            
            while (lft <= i && s[lft] == '0') lft++;

            if (cnt == k) {
                int curr = i - lft + 1;
                if (curr < len) {
                    len = curr;
                    st = lft; en = i;
                } else if (curr == len) {
                    if (s.compare(lft, curr, s, st, len) < 0) {
                        st = lft; en = i;
                    }
                }
            }
        }

        if (st == -1) return "";
        return s.substr(st, en - st + 1);
    }
};