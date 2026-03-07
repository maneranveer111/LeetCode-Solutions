class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prev = 0;

        for(string& log : logs) {
            int first = log.find(':');
            int second = log.find(':', first + 1);

            int fid = stoi(log.substr(0, first));
            string typ = log.substr(first + 1, second - first - 1);
            int time = stoi(log.substr(second + 1));

            if(typ == "start") {
                if(!st.empty())
                    res[st.top()] += time - prev;
                st.push(fid);
                prev = time;
            } 
            else {
                if(!st.empty()) 
                    res[st.top()] += time - prev + 1;
                    st.pop();
                prev = time + 1;    
            }
        }   

        return res;
    }
};