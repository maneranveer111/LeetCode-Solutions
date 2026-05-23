class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cows = 0;
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> mp2;
        unordered_map<int, int> mp3;

        for(int i = 0; i < secret.size(); i++) {
            mp[secret[i]].push_back(i);
            mp2[secret[i]]++;
            mp3[guess[i]]++;
        }    

        for(int j = 0; j < guess.size(); j++) {
            if(mp.find(guess[j]) != mp.end()) {
                int temp = 0;
                for(int i = 0; i < mp[guess[j]].size(); i++) {
                    if(mp[guess[j]][i] == j){
                        bull++;
                        mp2[guess[j]]--;
                        mp3[guess[j]]--;
                    }
                }
            }
        }
        
        for(int i = 0; i < secret.size(); i++) {
            if(mp.find(guess[i]) != mp.end()) {
                cows += min(mp2[guess[i]], mp3[guess[i]]);
                mp.erase(guess[i]);
            }
        }

        return to_string(bull) + "A" + to_string(cows) + "B";

    }
};