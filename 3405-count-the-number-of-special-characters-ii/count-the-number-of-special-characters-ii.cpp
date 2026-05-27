class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<vector<int>> occ(26);
        vector<int> vis(26, -1);
        int cnt = 0;

        for(int i = 0; i < word.size(); i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                occ[word[i] - 'a'].push_back(i);
            }
        }

        for(int i = 0; i < word.size(); i++) {
            if(word[i] >= 'A' && word[i] <= 'Z' && vis[word[i] - 'A'] == -1) {
                vis[word[i] - 'A'] = 1;
                char ch = tolower(word[i]);
                if(occ[ch - 'a'].size() == 0)
                    continue;
                bool flag = true;
                for(int j = 0; j < occ[ch - 'a'].size(); j++) {
                    if(occ[ch - 'a'][j] >= i)
                        flag = false;
                } 

                if(flag)
                    cnt++;
            }
        }

        return cnt;
    }
};