class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        stack<string> st;
        string ans = "";

        for(int i = 0; i < strs.size(); i++) {
            if(st.empty())
                st.push(strs[i]);
            else {
                string temp = st.top();
                st.pop();
                int j = 0;
                while(j < temp.size() && j < strs[i].size() && strs[i][j] == temp[j])
                    j++;

                st.push(temp.substr(0, j));

            }

        }

        return st.top();
    }
};