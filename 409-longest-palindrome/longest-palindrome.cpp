class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char, int> freq;
       for(char ch : s) freq[ch]++;
       int maxOdd = 0;
       int maxLen = 0; 
       bool hasOdd = false;
       for(auto it : freq) {
            int a = it.second;
            if(a % 2 == 0) maxLen += a;
            else {
                maxLen += a - 1;
                hasOdd = true;
            }
       }

        return (hasOdd) ? maxLen + 1 : maxLen;
    }
};