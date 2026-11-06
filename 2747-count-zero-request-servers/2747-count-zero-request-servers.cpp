class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {
        int m = logs.size();
        int q = queries.size();

        // Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        // Store query time and original index
        vector<pair<int, int>> qr;

        for (int i = 0; i < q; i++) {
            qr.push_back({queries[i], i});
        }

        sort(qr.begin(), qr.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(q);

        int left = 0, right = 0;
        int activeServers = 0;

        for (auto& [time, idx] : qr) {

            // Add logs whose time <= current query time
            while (right < m && logs[right][1] <= time) {
                int id = logs[right][0];

                freq[id]++;

                if (freq[id] == 1) {
                    activeServers++;
                }

                right++;
            }

            // Remove logs outside the interval [time-x, time]
            while (left < right && logs[left][1] < time - x) {
                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0) {
                    activeServers--;
                }

                left++;
            }

            // Servers that received zero requests
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};