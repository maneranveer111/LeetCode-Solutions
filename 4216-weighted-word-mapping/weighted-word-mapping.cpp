class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto& word : words) {
            int total = 0;
            for (char c : word)
                total += weights[c - 'a'];
            int mod = total % 26;
            ans += (char)('z' - mod);
        }
        return ans;   
    }
};