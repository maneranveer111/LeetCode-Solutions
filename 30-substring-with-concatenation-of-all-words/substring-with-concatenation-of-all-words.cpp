class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        unordered_map<string, int> freq;
        vector<int> ans;

        for(string word : words)
            freq[word]++;

        int cnt = words.size();
        int len = words[0].size();
        
        for(int i = 0; i < len; i++) {
            unordered_map<string, int> curr;
            int lft = i;
            int currCnt = 0;

            for(int j = i; j + len <= n; j += len) {
                string word = s.substr(j, len);

                if(freq.count(word)) {
                    curr[word]++;
                    currCnt++;

                    while(curr[word] > freq[word]) {
                        string st = s.substr(lft, len);
                        curr[st]--;
                        currCnt--;
                        lft += len;
                    }

                    if(currCnt == cnt) {
                        ans.push_back(lft);
                        string lw = s.substr(lft, len);
                        curr[lw]--;
                        currCnt--;
                        lft += len;
                    }
                }
                else {
                    curr.clear();
                    lft = j + len;
                    currCnt = 0;
                }
            }
        }

        return ans;
    }
};

