class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        int currNum = 0; 
        string currString = "";

        for(char ch : s) {
            if(isdigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            }
            else if(ch == '[') {
                st.push({currString, currNum});
                currString = "";
                currNum = 0;
            }
            else if(ch == ']') {
                auto [prevString, num] = st.top();
                st.pop();
                string repeated = "";

                for(int i = 0; i < num; i++) {
                    repeated += currString;
                }

                currString = prevString + repeated;
            }
            else {
                currString += ch;
            }
        }

        return currString;
    }
};