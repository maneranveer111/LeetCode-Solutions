class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
       int left = 0, right = 0;

       for(int i = 0; i < moves.size(); i++) {
            if(moves[i] == 'L') {
                left--;
                right--;
            }
            else if(moves[i] == 'R') {
                left++;
                right++;
            }
            else {
                left--;
                right++;
            }
       } 

       return (abs(left) > abs(right)) ? abs(left) : abs(right);
    }
}; 