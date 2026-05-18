class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;

        for(int i = 0; i < s.size(); i++) 
            count[s[i]]++;

        sort(s.begin(), s.end(), [&count](char a, char b) {
            if(count[a] == count[b])
                return a < b;  
            return count[a] > count[b];
        });

        return s;
    }
};