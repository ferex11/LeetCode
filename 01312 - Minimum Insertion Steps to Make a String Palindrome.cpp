// Recursion
class Solution {
private:
    int f(int i, int j, string& s) {
        if (i >= j) return 0;
        if (s[i] == s[j]) {
            return f(i + 1, j - 1, s);
        }
        return 1 + min(f(i + 1, j, s), f(i, j - 1, s));
    }
public:
    int minInsertions(string s) {
        return f(0, (int)s.length() - 1, s);
    }
};

// Memoization
class Solution {
private:
    int dp[501][501];
    int f(int i, int j, string& s) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = f(i + 1, j - 1, s);
        }
        return dp[i][j] = 1 + min(f(i + 1, j, s), f(i, j - 1, s));
    }
public:
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return f(0, (int)s.length() - 1, s);
    }
};

// Tabulation
class Solution {
public:
    int minInsertions(string s) {
        int n = (int)s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

// Space Optimization
class Solution {
public:
    int minInsertions(string s) {
        int n = (int)s.length();
        vector<int> front(n, 0), cur(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    cur[j] = front[j - 1];
                } else {
                    cur[j] = 1 + min(front[j], cur[j - 1]);
                }
            }
            front = cur;
        }
        return front[n - 1];
    }
};

// 1D - Space Optimization
class Solution {
public:
    int minInsertions(string s) {
        int n = (int)s.length();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int prev = 0;
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = prev;
                } else {
                    dp[j] = 1 + min(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[n - 1];
    }
};
