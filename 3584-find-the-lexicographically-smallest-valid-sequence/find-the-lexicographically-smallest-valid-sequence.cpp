class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        vector<int> suffix(m + 1, 0);
        int j = n - 1;
        for(int i = m - 1; i >= 0; i--) {
            if(j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suffix[i] = n - 1 - j;
        }

        bool used = false;
        int i = 0;
        j = 0;
        vector<int> res;
        
        while(i < m && j < n) {
            if(word1[i] == word2[j]) {
                res.push_back(i);
                i++;
                j++;
            }
            else if(!used  && suffix[i + 1] >= n - 1 - j) {
                res.push_back(i);
                i++;
                j++;
                used = true;
            }
            else
                i++;
        }

        if(j < n)
            return {};

        return res;
    }
};