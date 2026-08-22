class Solution {
public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int max_wealth = 0;
    for (auto& account : accounts) {
      int sum = 0;
      for (int x : account) {
        sum += x;
      }
      max_wealth = max(max_wealth, sum);
    }
    return max_wealth;
  }
};
