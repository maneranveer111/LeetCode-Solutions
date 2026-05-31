class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long ms = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i < asteroids.size(); i++) {
            if(asteroids[i] > ms)
                return false;
            ms += asteroids[i];
        }

        return true;
    }
};