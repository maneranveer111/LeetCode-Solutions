class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        vector<int> assign(ratings.size(), 1);

        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i - 1]) 
                assign[i] = assign[i - 1] + 1;
        }

        for(int i = assign.size() - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) {
                assign[i] = max(assign[i], assign[i + 1] + 1);
            }
        }

        for(int i = 0; i < assign.size(); i++) 
            ans += assign[i];

        return ans;
    }
};