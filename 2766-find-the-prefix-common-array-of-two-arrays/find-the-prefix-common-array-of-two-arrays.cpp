class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
        set<int> sta;
        set<int> stb;

        for(int i = 0; i < A.size(); i++) {
            sta.insert(A[i]);
            stb.insert(B[i]);

                if(A[i] == B[i])
                    ans[i] = (i > 0) ?  ans[i - 1] + 1 : 1;
                else {
                    int cnt = 0;
                    if(sta.find(B[i]) != sta.end() && sta.find(A[i]) != sta.end())
                        cnt++;
                    if(stb.find(A[i]) != stb.end() && stb.find(B[i]) != stb.end())
                        cnt++;

                    ans[i] = (i > 0) ? cnt + ans[i - 1] : cnt;
                }
            
        }

        return ans;
    }
};