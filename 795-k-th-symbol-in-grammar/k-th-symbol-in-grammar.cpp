class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;

        int mid = pow(2, n - 2);

        if(k <= mid) return kthGrammar(n - 1, k);
        else {
            int temp = kthGrammar(n - 1, k - mid);
            return flip(temp); 
        }  
    }

    int flip(int x) {
        if(x == 0) return 1;
        else return 0;
    }
};