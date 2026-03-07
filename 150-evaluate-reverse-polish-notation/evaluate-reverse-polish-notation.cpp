class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(string s : tokens) {
            int sz = s.size();
            if(isdigit(s[sz - 1])) {
                int num = 0;
                if(isdigit(s[0])) {
                    for(int i = 0; i < sz; i++) num = num * 10 + (s[i] - '0');
                    st.push(num);
                }
                else {
                    for(int i = 1; i < sz; i++) num = num * 10 + (s[i] - '0');
                    st.push(0 - num);
                }
            }
            if(sz == 1 && s[0] == '+') {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = b + a;
                st.push(res);
            }
            else if(sz == 1 && s[0] == '-') {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = a - b;
                st.push(res);
            }
            else if(sz == 1 && s[0] == '*') {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = a * b;
                st.push(res);
            }
            else if(sz == 1 && s[0] == '/') {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = a / b;
                st.push(res);
            }
        }

        return st.top();
    }
};