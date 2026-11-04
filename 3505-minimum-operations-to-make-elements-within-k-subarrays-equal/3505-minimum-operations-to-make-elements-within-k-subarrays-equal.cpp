
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Two multisets for sliding window median
        multiset<int> low, high;

        long long lowSum = 0;
        long long highSum = 0;

        // Maintain balanced multisets
        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();

                low.erase(prev(low.end()));
                lowSum -= val;

                high.insert(val);
                highSum += val;
            }

            while (low.size() < high.size()) {
                int val = *high.begin();

                high.erase(high.begin());
                highSum -= val;

                low.insert(val);
                lowSum += val;
            }
        };

        // Insert an element
        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                lowSum += val;
            }
            else {
                high.insert(val);
                highSum += val;
            }

            balance();
        };

        // Remove an element
        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                lowSum -= val;
            }
            else {
                it = high.find(val);
                high.erase(it);
                highSum -= val;
            }

            balance();
        };

        // Calculate cost of every window of size x
        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long operations =
                    median * (long long)low.size() - lowSum
                    + highSum - median * (long long)high.size();

                cost.push_back(operations);
            }
        }

        // DP: minimum cost to select j windows
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Skip current element
                dp[i][j] = dp[i - 1][j];

                // Select a window of size x
                if (i >= x) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
