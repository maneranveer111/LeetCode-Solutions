class Solution {
public:
    unordered_map<string, int> mp;
    string encode(vector<int> need) {
        string key = "";
        for(int x : need) {
            key += to_string(x);
            key += "#";
        }

        return key;
    }

    int helper(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        string key = encode(needs);
        if(mp.count(key))
            return mp[key];
        
        int base = 0;
        for(int i = 0; i < price.size(); i++) {
            base += price[i] * needs[i];
        }

        for(auto& of : special) {
            vector<int> newNeed = needs;
            bool ok = true;

            for(int i = 0; i < needs.size(); i++) {
                if(of[i] > needs[i]) {
                    ok = false;
                    break;
                }

                newNeed[i] = needs[i] - of[i];
            }

            if(ok) {
                base = min(base, of.back() + helper(price, special, newNeed));
            }

        }

        return mp[key] = base;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        mp.clear();
        return helper(price, special, needs);   
    }
};