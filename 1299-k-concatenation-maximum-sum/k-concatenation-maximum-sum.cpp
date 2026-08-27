class Solution {
public:
    long long kadanse(vector<int>& arr) {
        long long sum = 0, curr = 0;
        for(int x : arr) {
            curr = max((long long)curr + x, (long long)x);
            sum = max(curr, sum);
        }
        return sum;
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long MOD = 1e9 + 7;
        long long mini = *min_element(arr.begin(), arr.end());
        long long maxi = *max_element(arr.begin(), arr.end());
        
        if(mini >= 0) {
            long long sum = 0;
            for(int x : arr) sum = (sum + x) % MOD;
            return (k * sum) % MOD;
        } 
        else if(maxi <= 0) {
            return 0;
        } 
        else {
            long long kad = kadanse(arr);
            long long total = 0;
            for(int x : arr) total += x;
            
            long long maxiPre = 0, currPre = 0;
            for(int x : arr) {
                currPre += x;
                maxiPre = max(maxiPre, currPre);
            }
            
            long long maxiSuf = 0, currSuf = 0;
            for(int j = (int)arr.size() - 1; j >= 0; j--) {
                currSuf += arr[j];
                maxiSuf = max(currSuf, maxiSuf);
            }
            
            long long tmp = 0;
            if (k >= 2) {
                tmp += maxiPre + maxiSuf;
                tmp += (k - 2) * max(0LL, total);
            }
            
            long long ans = max(kad, tmp);
            return (int)(ans % MOD);
        }
    }
};
