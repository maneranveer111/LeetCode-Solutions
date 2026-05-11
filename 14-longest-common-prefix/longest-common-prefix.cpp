class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        stack<string> st;
        string ans = "";

        for(int i = 0; i < strs.size(); i++) {
            if(i == 0)
                ans = strs[i];
            else {
                int j = 0;
                while(j < ans.size() && j < strs[i].size() && strs[i][j] == ans[j])
                    j++;

                ans = ans.substr(0, j);

            }

        }

        return ans;
    }
};