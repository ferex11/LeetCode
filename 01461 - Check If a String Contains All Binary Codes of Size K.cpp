class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string> st;
        int len = 1 << k;
        for (int i = k; i <= n; i++) {
            string substring = s.substr(i - k, k);
            if (!st.count(substring)) {
                st.insert(substring);
                len--;
            }
            if (len == 0) return true;
        }
        return false;
    }
};
