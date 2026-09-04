class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            int  maxi=INT_MIN;
            int  mini=INT_MAX;
             int r=-1;
            for(int j=0; j<=i; j++){
                maxi=max(maxi,nums[j]);
            }
            for(int j=i; j<nums.size(); j++){
                if(nums[j]<mini){
                    mini=nums[j];
                    r=j;
                }
            }
            if((maxi-mini)<=k){
                return i;
            }
        }
        return -1;
    }
};