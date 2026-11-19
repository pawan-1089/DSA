class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Case 1: Change the 2 smallest elements
        int case1 = nums[n - 1] - nums[2];
        
        // Case 2: Change the 2 largest elements
        int case2 = nums[n - 3] - nums[0];
        
        // Case 3: Change 1 smallest and 1 largest element
        int case3 = nums[n - 2] - nums[1];
        
        return min({case1, case2, case3});
    }
};
