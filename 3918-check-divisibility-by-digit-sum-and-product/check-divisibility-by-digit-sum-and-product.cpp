class Solution {
public:
    bool checkDivisibility(int n) {
        string num = to_string(n);
        int digSum = 0, digPro = 1;

        for(char ch : num) {
            digSum += (ch - '0');
            digPro *= (ch - '0');
        }   

        return !(n % (digSum + digPro));
    }
};