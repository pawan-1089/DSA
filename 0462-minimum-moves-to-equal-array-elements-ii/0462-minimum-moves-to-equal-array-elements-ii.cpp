class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=nums[n/2];
        long long moves=0;
        for(auto it:nums){
            moves+=abs((long long)it-median);
        }
        return moves;
    }
};