class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndx=0;
        int n=nums.size()-1;
        for(int i=0; i<nums.size(); i++){
            if(i>maxIndx)return false;
            if(maxIndx>=n)return true;
            int x=nums[i]+i;
            maxIndx=max(maxIndx,x);
        }
        return false;
    }
};