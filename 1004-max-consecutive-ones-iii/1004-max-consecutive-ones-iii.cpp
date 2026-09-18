class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        int len=0;
        int r=0;
        int l=0;
        int zeros=0;
        while(r<n){
            if(nums[r]==0){
                zeros++;
            }
            while(zeros>k && l<n){
                if(nums[l]==0){
                    zeros--;
                }
                l=l+1;
            }
            if(zeros<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};