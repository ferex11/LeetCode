class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x != 0) {
            long long rem = x % 10;
            if( (ans * 10 > INT_MAX) || (ans * 10 < INT_MIN)) {
                return 0;
            }
            ans = (ans * 10) + rem;
            x /= 10;
        }
        return ans;;
    }
};
