class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(0);

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(0);
            else {
                if(st.top() == 0) {
                    st.pop();
                    st.top() = st.top() + 1;
                }
                else {
                    int sc = st.top() * 2;
                    st.pop();
                    st.top() = st.top() + sc;
                }
            }
        }    

        return st.top();
    }
};