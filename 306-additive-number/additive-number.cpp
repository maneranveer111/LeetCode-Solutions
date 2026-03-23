class Solution {
public:
    string addStrings(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result += (char)('0' + sum % 10);
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool helper(string a,string b, int idx, string num) {
        if(idx == num.size()) return true;
    
        string sum = addStrings(a, b);

        if (num.substr(idx, sum.size()) != sum)
            return false;

        return helper(b, sum, idx + sum.size(), num);
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for(int i = 1; i <= n / 2; i++) {
            for(int j = 1; j <= n - i; j++) {
                if(num[0] == '0' && i > 1) break;
                if(num[i] == '0' && j > 1) break;

                if (i + j >= n) break;
                string sa = num.substr(0, i);
                string sb = num.substr(i, j);

                if(helper(sa, sb, i + j, num))
                    return true;
            }
        }

        return false;
    }
};