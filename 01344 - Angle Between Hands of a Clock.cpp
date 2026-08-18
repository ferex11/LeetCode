class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = hour * 30;
        double min_angle = minutes * 5.5;
        double diff = abs(hour_angle - min_angle);
        return min(diff, 360 - diff);
    }
};
