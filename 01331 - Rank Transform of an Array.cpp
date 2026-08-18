class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    int n = (int) arr.size();
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    int x = 1;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      if (!mp[temp[i]]) {
        mp[temp[i]] = x;
        x++;
      }
    }
    for (int i = 0; i < n; i++) {
      arr[i] = mp[arr[i]];
    }
    return arr;
  }
};
