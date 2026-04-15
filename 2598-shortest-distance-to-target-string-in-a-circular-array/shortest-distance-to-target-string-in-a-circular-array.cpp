class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int forward = (i - startIndex + n) % n;
                int backward = (startIndex - i + n) % n;
                minDist = min(minDist, min(forward, backward));
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};