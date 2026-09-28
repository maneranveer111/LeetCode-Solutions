class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        unordered_map<string, string> mp;
        for(auto know : knowledge) {
            mp[know[0]] = know[1];
        }

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                string key = "";
                int j = i + 1;
                while(j < s.size() && s[j] != ')') {
                    key.push_back(s[j]);
                    j++;
                }
                i = j;
                
                if(mp.find(key) != mp.end()) 
                    ans += mp[key];
                else 
                    ans.push_back('?');
            }
            else
                ans.push_back(s[i]);
        }

        return ans;
    }
};