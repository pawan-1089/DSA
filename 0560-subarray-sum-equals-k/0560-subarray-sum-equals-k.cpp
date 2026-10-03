class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long prefixsum=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int ans=0;
        for(auto x:nums){
            prefixsum+=x;
            if(mpp.find(prefixsum-k)!=mpp.end()){
                ans+=mpp[prefixsum-k];
            }
            mpp[prefixsum]++;
        }
        return ans;
    }
};