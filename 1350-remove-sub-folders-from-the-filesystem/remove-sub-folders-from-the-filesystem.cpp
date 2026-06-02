class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        
        vector<string> ans;
        ans.push_back(folder[0]);
        
        for (int i = 1; i < folder.size(); i++) {
            string last = ans.back();
            string curr = folder[i];
            
            if (curr.find(last) == 0 && curr[last.size()] == '/') {
                continue;  
            }
            
            ans.push_back(curr);
        }
        
        return ans;
    }
};