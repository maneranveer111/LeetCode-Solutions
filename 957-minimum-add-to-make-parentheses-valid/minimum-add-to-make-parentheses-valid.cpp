class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int moves = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') st.push('(');
            else {
                if(st.empty()) moves++;
                else if(st.top() == '(') st.pop();
            }
        }

        moves += st.size();

        return  moves;

    }
};