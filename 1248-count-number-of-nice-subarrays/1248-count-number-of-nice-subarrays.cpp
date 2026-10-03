class Solution {
public:
    int solve(vector<int>&nums,int k){
        if(k<0)return 0;
        int l=0;
        int r=0;
        int odd=0;
        int cnt=0;
        while(r<nums.size()){
            if(nums[r]%2==1){
                odd++;
            }
            while(odd>k){
                if(nums[l]%2==1){
                    odd--;
                }
                l++;
            }
            if(odd<=k){
                cnt=cnt+(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //find no. of odds with <=k
        //find no. of odds wiht <=k-1'
        //sub then we got no. of odds wiht ==k;
        //Toc O(2*2N)
        int s1=solve(nums,k);
        int s2=solve(nums,k-1);
        int ans=s1-s2;
        return ans;
    }
};