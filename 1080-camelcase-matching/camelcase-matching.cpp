class Solution {
public:
    bool matches(const string& query, const string& pattern) {
        int j = 0; 
        for (int i = 0; i < query.size(); i++) {
            if (j < pattern.size() && query[i] == pattern[j]) {
                j++;
            }
            else if (isupper(query[i])) {
                return false;
            }
        }
        
        return j == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        
        for (const string& query : queries) {
            answer.push_back(matches(query, pattern));
        }
        
        return answer;   
    }
};
