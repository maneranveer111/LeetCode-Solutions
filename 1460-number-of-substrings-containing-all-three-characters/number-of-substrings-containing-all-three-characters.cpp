class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        // unordered_map<char, int>
        int mini = -1, maxi = -1;
        for(int i = 0; i < s.size(); i++) {
            int a = -1, b = -1, c = -1;
            if(mini < i) {
                for(int j = i; j < s.size(); j++) {
                    if(s[j] == 'a') {
                        a = j;
                    }
                    else if(s[j] == 'b') {
                        b = j;
                    }
                    else if(s[j] == 'c') {
                        c = j;
                    }
                    if (a != -1 && b != -1 && c != -1) break;
                }
            }
            else {
                ans += (int)s.size() - maxi;
                continue;
            }

            maxi = max({a, b, c});
            mini = min({a, b, c});

            if (a != -1 && b != -1 && c != -1)
                ans += (int)s.size() - maxi;
        }

        return ans;
    }
};