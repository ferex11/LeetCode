class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int k = 0; k <= 31; k++) {
            int countOnes = 0;
            for (auto &num : nums) {
                if ((num & (1 << k)) != 0) {
                    countOnes++;
                }
            }
            if (countOnes % 3 == 1) {
                res = res | (1 << k);
            }
        }
        return res;
    }
};
