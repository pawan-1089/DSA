class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d * 2 <= len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }
        
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d : divisors[len]) {
                    int changes = 0;
                    // Check each of the d interleaved groups
                    for (int rem = 0; rem < d; ++rem) {
                        int left = i + rem;
                        int right = j - (d - 1 - rem);
                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        
        // dp[p][i] = min changes to partition prefix of length i into p semi-palindromes
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            // Each partition needs at least 2 characters, so i >= 2 * p
            for (int i = 2 * p; i <= n; ++i) {
                for (int j = 2 * (p - 1); j <= i - 2; ++j) {
                    if (dp[p - 1][j] != INF && cost[j][i - 1] != INF) {
                        dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
                    }
                }
            }
        }
        
        return dp[k][n];
    }
};
