class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int cnt = 1;
        set<int> st;

        for(int i : nums) 
            st.insert(i);
        
        while(true) {
            if(st.find(cnt) == st.end())
                return cnt;
            cnt++;
        }

        return cnt;
        
    }
};