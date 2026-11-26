class Solution {
public:
    bool canAliceWin(int n) {
        int cnt = 10;
        bool aliceTurn = true;

        while (true) {
            if (n < cnt)               
                return !aliceTurn;     

            n -= cnt;
            cnt--;
            aliceTurn = !aliceTurn;
        }
    }
};