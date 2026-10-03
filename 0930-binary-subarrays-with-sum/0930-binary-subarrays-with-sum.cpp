class Solution {
public:
    int solve(vector<int>&nums,int goal){
        if(goal<0)return 0;
        int l=0;
        int r=0;
        int cnt=0;
        long long sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            if(sum<=goal){
                cnt=cnt+(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s1=solve(nums,goal);
        int s2=solve(nums,goal-1);
        int ans=s1-s2;
        return ans;
    }
};