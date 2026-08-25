class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> multK;
        for(int x : nums) {
            if(x % k == 0)
                multK.push_back(x);
        }
        int tmp = k;
        sort(multK.begin(), multK.end());
        multK.erase(unique(multK.begin(), multK.end()), multK.end());

        for(int x : multK)
            cout << x << " ";
        cout << endl;

        for(int x : multK) {
            if(x != k)
                return k;
            k += tmp;
        }

        return k;
    }
};