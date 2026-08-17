// Brute Force Approach 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Optimal Approach : Hash Map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int x = target - nums[i];

            if (mpp.find(x) != mpp.end()) {
                return {i, mpp[x]};
            }
            mpp[nums[i]] = i;
        }        

        return {-1, -1};
    }
};
