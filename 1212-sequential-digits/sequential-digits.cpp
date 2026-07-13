class Solution {
public:
    vector<int> ans;

    void helper(int sz, string& s, int low, int high) {
        int j = 0;
        for(int i = sz; i <= s.size(); i++) {
            string str = s.substr(j, sz);
            int nm = stoi(str);
            if(nm >= low && nm <= high)
                ans.push_back(nm);
            j++;
        }
    } 

    vector<int> sequentialDigits(int low, int high) {
        string lw = to_string(low), hi = to_string(high);
        int l1 = lw.size(), l2 = hi.size();

        string s = "123456789";

        for(int i = l1; i <= l2; i++) {
            helper(i, s, low, high);
        }

        return ans;
    }
};