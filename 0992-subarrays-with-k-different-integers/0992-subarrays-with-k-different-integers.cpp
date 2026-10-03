class Solution {
public:
    int solve(vector<int>&nums,int k){
        if(k<0)return 0;
        int l=0;
        int r=0;
        int cnt=0;
        unordered_map<int,int>mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if(mpp.size()<=k){
                cnt=cnt+(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int s1=solve(nums,k);
        int s2=solve(nums,k-1);
        int ans=s1-s2;
        return ans;
    }
};