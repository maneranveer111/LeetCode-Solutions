class Solution {
public:
    bool willMake(int idx, int side, vector<int>& matchsticks, vector<int>& squareSides) {
        if(idx == matchsticks.size() && squareSides[0] == side &&
            squareSides[1] == side && squareSides[2] == side && squareSides[3] == side)
                return true;

        for(int i = 0; i < 4; i++) {
            if(squareSides[i] + matchsticks[idx] > side)
                continue;
            
            squareSides[i] += matchsticks[idx];
            if(willMake(idx + 1, side, matchsticks, squareSides))
                return true;
            
            squareSides[i] -= matchsticks[idx];

            if(squareSides[i] == 0)
                break;
        }

        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int perimeter = 0, maxi = INT_MIN;
        for(int p : matchsticks) {
            perimeter += p;
            maxi = max(maxi, p);
        }

        if(perimeter % 4 != 0)
            return false;
        int side = perimeter / 4;
        if(maxi > side)
            return false;

        vector<int> squareSides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());

        return willMake(0, side, matchsticks, squareSides);
    }
};