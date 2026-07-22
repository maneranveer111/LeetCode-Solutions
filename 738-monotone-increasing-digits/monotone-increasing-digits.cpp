class Solution {
public:
    bool helper(int idx, string& curr, string& num) {
        if (idx == num.size())
            return curr <= num;  

        if (curr > num.substr(0, idx))
            return false;

        char start = curr.empty() ? '0' : curr.back();

        for (char ch = '9'; ch >= start; ch--) {
            curr.push_back(ch);
            if (helper(idx + 1, curr, num))
                return true;
            curr.pop_back();
        }

        return false;
    }

    int monotoneIncreasingDigits(int n) {
        if (n < 10)
            return n;

        string num = to_string(n);
        string curr = "";
        helper(0, curr, num);
        return stoi(curr);
    }
};