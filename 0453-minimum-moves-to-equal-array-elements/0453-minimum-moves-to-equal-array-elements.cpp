class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt=0;
        long long sum=0;
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        for(auto x:nums){
            sum+=x;
        }
        return sum-(long long)n*mini;
    }
};