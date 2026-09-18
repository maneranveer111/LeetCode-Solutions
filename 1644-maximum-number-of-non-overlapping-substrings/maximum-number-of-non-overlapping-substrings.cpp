class Solution {
public:
    int helper(int idx, string& s, vector<pair<int, int>>& firstLast) {
        int j = firstLast[s[idx] - 'a'].second;

        for(int i = idx; i <= j; i++) {
            int c = s[i] - 'a';
            if(firstLast[c].first < idx)
                return -1;
            j = max(j, firstLast[c].second);
        }
        return j;
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int, int>> firstLast(26, {-1, -1});

        for(int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if(firstLast[ch].first == -1)
                firstLast[ch].first = i;
            firstLast[ch].second = i;
        }

        vector<pair<int, int>> res;

        for(int i = 0; i < s.size(); i++) {
            if(i != firstLast[s[i] - 'a'].first)
                continue;

            int rht = helper(i, s, firstLast);
            if(rht == -1)
                continue;

            if(!res.empty() && i <= res.back().second)
                res.back() = {i, rht};
            else
                res.push_back({i, rht});
        }

        vector<string> ans;
        for(auto& [l, r] : res)
            ans.push_back(s.substr(l, r - l + 1));
        return ans;
    }
};