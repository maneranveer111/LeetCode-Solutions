class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxFreq = 0, freQent = 0;
        vector<int> freq(26, 0);

        for(char ch : tasks) {
            freq[ch - 'A']++;
            maxFreq = max(maxFreq, freq[ch - 'A']);
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] == maxFreq)
                freQent++;
        }

        int ans = (maxFreq - 1) * (n + 1) + freQent;
        ans = max(ans, (int)tasks.size());
        return ans;
    }
};