class Solution {
public:
    
    vector<string> helper(string s) {
        vector<string> ans;
        int n = s.size();

        if(s[0] != '0' || s == "0")
            ans.push_back(s);
        
        for(int i = 1; i < n; i++) {
            string l = s.substr(0, i);
            string r = s.substr(i);

            if(l[0] == '0' && l != "0")
                continue;
            
            if(r.back() == '0')
                continue;
            
            ans.push_back(l + "." + r);
        }

        return ans;
    }

    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.size() - 2);
        int n = s.size();

        vector<string> ans;

        for(int i = 1; i < n; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            vector<string> lft = helper(left);
            vector<string> rht = helper(right);

            for(string& l : lft) {
                for(string& r : rht) {
                    ans.push_back("(" + l + ", " + r + ")");
                }
            }
        }

        return ans;
 
    }
};