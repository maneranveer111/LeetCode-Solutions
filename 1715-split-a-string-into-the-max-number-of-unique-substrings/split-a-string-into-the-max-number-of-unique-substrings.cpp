class Solution {
public:
    int ans = 0;

    void helper(string& s, int idx, set<string> st, int cnt) {
        if(cnt + (int)(s.size() - idx) <= ans) 
            return;
        
        if(idx == s.size()) {
            ans = max(ans, cnt);
            return;
        }

        string curr = "";

        for(int i = idx; i < s.size(); i++) {
            curr += s[i];
            if(!st.count(curr)) {
                st.insert(curr);
                helper(s, i + 1, st, cnt + 1);
                st.erase(curr);
            }
        }
    }

    int maxUniqueSplit(string s) {
        set<string> st;
        helper(s, 0, st, 0);
        return ans;
    }
};