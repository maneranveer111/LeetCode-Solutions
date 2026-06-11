class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seen;
        vector<string> result;
        
        for (int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10);
            if (++seen[sub] == 2) {
                result.push_back(sub);
            }
        }
        
        return result;
    }
};