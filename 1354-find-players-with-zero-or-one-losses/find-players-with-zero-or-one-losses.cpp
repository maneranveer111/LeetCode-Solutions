class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winLoss;
        unordered_map<int, int> lossWin;

        for(auto match : matches) {
            int win = match[0];
            int loss = match[1];

            winLoss[win]++;
            lossWin[loss]++;
        }

        vector<int> noDefeat;
        for(auto [key, val] : winLoss) {
            if(!lossWin.count(key))
                noDefeat.push_back(key);
        }

        vector<int> oneLoss;
        for(auto [key, val] : lossWin) {
            if(val == 1)
                oneLoss.push_back(key);
        }

        sort(noDefeat.begin(), noDefeat.end());
        sort(oneLoss.begin(), oneLoss.end());

        vector<vector<int>> ans;
        ans.push_back(noDefeat);
        ans.push_back(oneLoss);

        return ans;
    }
};