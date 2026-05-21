class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;

        for(int i = 0; i < arr1.size(); i++) {
            string s = to_string(arr1[i]);
            for(int j = 0; j < s.size(); j++) {
                st.insert(s.substr(0, j + 1));
            }
        }

        string ans = "";
        int len = 0;

        for(int i = 0; i < arr2.size(); i++) {
            string s = to_string(arr2[i]);
            for(int j = 0; j < s.size(); j++) {
                if(st.find(s.substr(0, j + 1)) != st.end()) {
                    if(ans.size() < j + 1) {
                        ans = s.substr(0, j + 1);
                        len = max(len, j + 1);
                    }
                }
            }
        }

        return len;
    }
};