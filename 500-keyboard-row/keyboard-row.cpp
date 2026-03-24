class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> first = 
        {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        vector<string> ans;

        for(int i = 0; i < words.size(); i++) {
            int prev = -1;
            bool isTrue = true;
            for(char c : words[i]) {
                c = tolower(c);
                if(prev == -1) {
                    prev = first[c - 'a'];
                }
                else {
                    if(prev != first[c - 'a']) {
                        isTrue = false;
                        break;
                    }
                }
            }
            if(isTrue) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};