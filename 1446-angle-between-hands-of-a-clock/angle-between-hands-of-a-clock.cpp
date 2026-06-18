class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hAng = 0.5 * (hour * 60 + minutes);
        double minAng = 6.0 * minutes;

        double angle = abs(hAng - minAng);

        return (angle > 180) ? 360 - angle : angle;  
    }
};