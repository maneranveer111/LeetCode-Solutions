class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();

        vector<pair<long long, long long>> st;

        for(int i = n - 1; i >= 0; i--) {
            int currPos = position[i];
            int currSpeed = speed[i];

            if(!st.empty()) {
                long long topSpeed = st.back().second;
                long long topPos = st.back().first;
                long long dif = topPos - currPos;
                
                if(dif <= distance || currSpeed > topSpeed) {
                    st.pop_back();
                    st.push_back({currPos, topSpeed});
                    continue;
                }
            }

            st.push_back({currPos, currSpeed});
        }

        

        return (int)st.size();
    }
};