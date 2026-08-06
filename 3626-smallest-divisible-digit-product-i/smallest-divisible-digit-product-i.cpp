class Solution {
public:
    int smallestNumber(int n, int t) {
        int pro = 1;
        string num = to_string(n);

        for(char ch : num) {
            pro *= (int)(ch - '0');
        }

        if(pro % t == 0)
            return n;

        char ch = num[num.size() - 1];
        int npro = pro / (int)(ch - '0');

        for(char c = ch + 1; c <= '9'; c++) {
            if((npro * (int)(c - '0')) % t == 0) {
                num[num.size() - 1] = c;
                int nm = stoi(num);
                return nm;
            }
        }

        int rem = n % 10;
        rem = 10 - rem;

        return n + rem;
    }
};