class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int cur = 0;
        for (int x : gain) {
            cur += x;
            mx = max(mx, cur);
        }
        return mx;
    }
};
