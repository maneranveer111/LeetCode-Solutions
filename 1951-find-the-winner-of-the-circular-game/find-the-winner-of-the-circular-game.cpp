class Solution {
public:
    int winner(int n , int k) {
        if(n == 1) return  0;
        
        int win = winner(n - 1, k);

        return (win + k) % n;
    }

    int findTheWinner(int n, int k) {
        return winner(n , k) + 1;    
    }
};