class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int len = word.size(); 

        int win = len / 8;
        int rem = len % 8;

        for(int i = 1; i <= win; i++) {
            ans += i * 8;
        }

        ans += (win + 1) * rem;

        return ans;
    }
};