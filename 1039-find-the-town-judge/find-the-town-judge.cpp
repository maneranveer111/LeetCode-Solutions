class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> degrees(n + 1);

        for(auto tru : trust) {
            degrees[tru[0]].second++;
            degrees[tru[1]].first++;
        }

        for(int i = 1; i <= n; i++)
            if(degrees[i].first == n - 1 && degrees[i].second == 0)
                return i;

        return -1;
    }
};