class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        
        // Stores {current_raised_value, count_of_elements}
        deque<pair<long long, int>> dq;
        int r = n - 1;
        
        for (int l = n - 1; l >= 0; --l) {
            int count = 1;
            // Merge all elements to the right that are smaller than nums[l]
            while (!dq.empty() && dq.front().first < nums[l]) {
                auto [val, cnt] = dq.front();
                dq.pop_front();
                cost += (nums[l] - val) * cnt;
                count += cnt;
            }
            dq.push_front({nums[l], count});
            
            // Shrink from the right if total operations exceed k
            while (cost > k) {
                cost -= (dq.back().first - nums[r]);
                dq.back().second--;
                if (dq.back().second == 0) {
                    dq.pop_back();
                }
                r--;
            }
            
            // All subarrays starting at l and ending in [l, r] are valid
            ans += (r - l + 1);
        }
        
        return ans;
    }
};
