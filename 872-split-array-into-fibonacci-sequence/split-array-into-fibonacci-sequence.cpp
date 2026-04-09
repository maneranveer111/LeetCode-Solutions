class Solution {
public:
    vector<int> ans;

    vector<long long> helper(string num, long long num1, long long num2, int pos) {
        vector<long long> res = {num1, num2};

        while(pos < num.size()) {
            long long next = num1 + num2;
            if(next > INT_MAX) return {};
            string nextStr = to_string(next);

            if(num.substr(pos, nextStr.size()) != nextStr)
                return {};
            
            res.push_back(next);
            num1 = num2;
            num2 = next;
            pos += nextStr.size();
        }

        if(res.size() >= 3)
            return res;
        
        return {};
    }
    vector<int> splitIntoFibonacci(string num) {
        int n = num.size();
        long long INT_LIMIT = INT_MAX;

        for(int i = 1; i < n; i++) {
            string n1 = num.substr(0, i);
            if(n1.size() > 1 && n1[0] == '0')
                break;
            
            long long num1 = stoll(n1);
            if(n1.size() > 10 || num1 > INT_LIMIT)
                break;
            
            for(int j = i + 1; j < n; j++) {
                string n2 = num.substr(i, j - i);
                if(n2.size() > 1 && n2[0] == '0')
                    break;
                
                long long num2 = stoll(n2);
                if(n2.size() > 10 || num2 > INT_LIMIT)
                    break;
                
                vector<long long> result = helper(num, num1, num2, j);

                if(!result.empty()) {
                    vector<int> ans;

                    for(long long nm : result) {
                        ans.push_back((int)nm);
                    }

                    return ans;
                }

            }
        }

        return {};
    }
};