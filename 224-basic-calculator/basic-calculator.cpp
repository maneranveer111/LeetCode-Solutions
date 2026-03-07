class Solution {
public:
    int calculate(string s) {
        int ans = 0, sign = 1;
        long long num = 0;
        stack<pair<int, int>> st;

        for(char c : s) {
            if(isdigit(c)) {
                num = num * 10 + (c - '0');   
            }
            else if(c == '+') { 
                ans += sign * num; sign = +1; num = 0;
            }
            else if(c == '-') { 
                ans += sign * num; sign = -1; num = 0; 
            }
            else if (c == '(') {
                st.push({ans, sign});
                ans = 0;
                sign = 1;
            }
            else if(c == ')') {
                ans += sign * num;       
                num = 0;                  
                auto [saved_ans, saved_sign] = st.top();
                st.pop();                
                ans = saved_ans + saved_sign * ans;
            }
                
        }
        return ans + sign * num;
    }
};