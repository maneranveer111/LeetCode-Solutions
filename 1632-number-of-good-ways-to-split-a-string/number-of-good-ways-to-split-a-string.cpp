class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> lftrht(n + 1, 0);
        vector<int> rhtlft(n + 1, 0);
        unordered_set<char> freq;

        for(int i = 0; i < n; i++) {
            freq.insert(s[i]);
            lftrht[i + 1] = freq.size();
        }

        freq.clear();
        for(int i = n -1; i >= 0; i--) {
            freq.insert(s[i]);
            rhtlft[i] = freq.size();
        }
        int cnt = 0;
        for(int i = 0; i <= n; i++) {
            if(lftrht[i] == rhtlft[i])
                cnt++;
        }

        return cnt;
    }
};