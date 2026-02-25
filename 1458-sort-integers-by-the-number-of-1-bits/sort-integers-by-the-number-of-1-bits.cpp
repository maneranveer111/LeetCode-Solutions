class Solution {
public:
    static int countBits(int n) {
        int count = 0;
        while(n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int aBit = countBits(a);
            int bBit = countBits(b);
            
            if(aBit == bBit)
                return a < b;     
            return aBit < bBit;  
        });
        
        return arr;
    }
};