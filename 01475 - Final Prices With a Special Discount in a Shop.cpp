class Solution {
public:
  vector<int> finalPrices(vector<int>& prices) {
    int n = (int) prices.size();
    vector<int> answer(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && st.top() > prices[i]) {
        st.pop();
      }
      if (st.empty()) {
        answer[i] = prices[i];
      } else {
        answer[i] = prices[i] - st.top();
      }
      st.push(prices[i]);
    }
    return answer;
  }
};
