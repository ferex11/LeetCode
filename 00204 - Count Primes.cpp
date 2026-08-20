class Solution {
private:
    vector<bool> sieve;
    void compute_sieve(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i)
                    sieve[j] = false;
            }
        }
    }
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        sieve.resize(n + 1, true);
        compute_sieve(n);
        int countPrimes = 0;
        for (int i = 2; i <= n; i++) {
            if (sieve[i] && i < n)
                countPrimes++;
        }
        return countPrimes;
    }
};
