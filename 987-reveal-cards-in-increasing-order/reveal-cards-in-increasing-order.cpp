class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size());
        int i = 0;
        queue<int> q;

        for(int j = 0; j < deck.size(); j++)
            q.push(j);
        
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            ans[idx] = deck[i];
            i++;

            if(!q.empty()) {
                int lidx = q.front();
                q.pop();
                q.push(lidx);
            }
        }   

        return ans;
    }
};