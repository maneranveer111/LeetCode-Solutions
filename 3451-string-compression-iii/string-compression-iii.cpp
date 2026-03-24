class Solution {
public:
    string compressedString(string chars) {
        int n = chars.size();
        int idx = 0;
        string ans = "";

        for(int i = 0; i < n; i++){
            int count = 0;
            char ch = chars[i];
            while(i < n && ch == chars[i]){
             count++; i++;
            }
            if(count <= 9) {
                ans += to_string(count);
                ans += ch;
            }
            else{
                int cnt = count / 9;
                int mod = count % 9;
                for(int i = 0; i < cnt; i++) {
                    ans += "9";
                    ans += ch;
                }

                if(mod != 0) ans += to_string(mod);
                if(mod != 0) ans += ch;
                
            }   
            i--;
        }
        return ans;
    }
};