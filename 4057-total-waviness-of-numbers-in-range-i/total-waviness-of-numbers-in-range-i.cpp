class Solution {
public:
    unordered_map<string, int> mp;

    int findPeakVally(string nm) {
        int peak = 0, vally = 0;

        if(mp.find(nm) != mp.end())
            return mp[nm];

        for(int i = 1; i < nm.size() - 1; i++) {
            if(nm[i] > nm[i + 1] && nm[i] > nm[i - 1])
                peak++;
            else if(nm[i] < nm[i + 1] && nm[i] < nm[i - 1])
                vally++;
        }

        return mp[nm] = peak + vally;
    }
    
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++) {
            string st = to_string(i);
            for(int i = 0; i + 2 <= st.size() - 1; i++) {
                ans += findPeakVally(st.substr(i, 3));
            }
        }

        return ans;
    }
};