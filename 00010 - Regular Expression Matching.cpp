// Recursion
class Solution {
private:
    bool f(int i, int j, string& s, string& p) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (i >= 0 && j < 0) {
            while (i >= 0) {
                if (p[i] != '*')
                    return false;
                i -=  2;
            }
            return true;
        }
        if (p[i] == s[j] || p[i] == '.')
            return f(i - 1, j - 1, s, p);
        if (p[i] == '*') {
            bool notTake = f(i - 2, j, s, p);
            bool take = false;
            if (p[i - 1] == s[j] || p[i - 1] == '.')
                take = f(i, j - 1, s, p);
            return take || notTake;
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        return f(n - 1, m - 1, s, p);
    }
};

// Memoization
class Solution {
private:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (i >= 0 && j < 0) {
            while (i >= 0) {
                if (p[i] != '*')
                    return false;
                i -=  2;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[i] == s[j] || p[i] == '.')
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        if (p[i] == '*') {
            bool notTake = f(i - 2, j, s, p, dp);
            bool take = false;
            if (p[i - 1] == s[j] || p[i - 1] == '.')
                take = f(i, j - 1, s, p, dp);
            return dp[i][j] = take || notTake;
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
};

// Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*')
                dp[i][0] = dp[i - 2][0];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*') {
                    bool notTake = dp[i - 2][j];
                    bool take = false;
                    if (p[i - 2] == s[j - 1] || p[i - 2] == '.')
                        take = dp[i][j - 1];
                    dp[i][j] = take || notTake;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<bool> prev2(m + 1, false);
        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);
        prev[0] = true;
        for (int i = 1; i <= n; i++) {
            cur.assign(m + 1, false);
            if (p[i - 1] == '*') {
                if (i >= 2)
                    cur[0] = prev2[0];
            }
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '.') {
                    cur[j] = prev[j - 1];
                } else if (p[i - 1] == '*') {
                    bool notTake = prev2[j];
                    bool take = false;
                    if (p[i - 2] == s[j - 1] || p[i - 2] == '.')
                        take = cur[j - 1];
                    cur[j] = take || notTake;
                } else {
                    cur[j] = false;
                }
            }
            prev2 = prev;
            prev = cur;
        }
        return prev[m];
    }
};
