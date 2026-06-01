class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        int m1=0,m2=0,m3=0;
        char c1='*',c2='*',c3='*';

        for(auto& it: mp){
            if(it.second > n/4){
                if(c1=='*'){m1=it.second-n/4; c1=it.first;}
                else if(c2=='*'){m2=it.second-n/4; c2=it.first;}
                else{m3=it.second-n/4; c3=it.first;}
            }
        }

        if(m1==0 && m2==0 && m3==0) return 0;

        int curr1=0, curr2=0, curr3=0;
        int lft=0, ans=INT_MAX;

        for(int i=0; i<n; i++){
            if(s[i]==c1) curr1++;
            else if(s[i]==c2) curr2++;
            else if(s[i]==c3) curr3++;

            while(curr1>=m1 && curr2>=m2 && curr3>=m3){
                ans = min(ans, i-lft+1);
                if(s[lft]==c1) curr1--;
                else if(s[lft]==c2) curr2--;
                else if(s[lft]==c3) curr3--;
                lft++;
            }
        }

        return ans;
    }
};