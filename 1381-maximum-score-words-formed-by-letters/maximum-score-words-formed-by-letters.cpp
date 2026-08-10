class Solution {
public:
    unordered_map<char, int> mp;
    vector<int> help;
    int n;
    unordered_map<string, int> memo;

    int cango(unordered_map<char, int>& curr) {
        int scr = 0;
        for(auto [key, val] : curr) {
            if(mp[key] < val)
                return 0;
            scr += help[key - 'a'] * val;
        }
        return scr;
    }

    string findKey() {
        string s;
        s.reserve(26);
        for(char c = 'a'; c <= 'z'; c++) {
            s += (char)('0' + min(mp[c], 25)); 
        }
        return s;
    }

    int findScore(int idx, vector<string>& words) {
        if(idx == n)
            return 0;

        string key = to_string(idx) + "#" + findKey();
        if(memo.count(key))
            return memo[key];

        int take = 0, nontake = 0;
        unordered_map<char, int> curr;
        for(char ch : words[idx]) 
            curr[ch]++;

        int temp = cango(curr);
        if(temp > 0) {
            for(auto [k, val] : curr) 
                mp[k] -= val;
            
            take = temp + findScore(idx + 1, words);
            
            for(auto [k, val] : curr) 
                mp[k] += val;
        }

        nontake = findScore(idx + 1, words);

        int result = max(take, nontake);
        memo[key] = result;
        return result;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        mp.clear();
        memo.clear();
        help = score;
        for(char ch : letters) 
            mp[ch]++;

        return findScore(0, words);
    }
};