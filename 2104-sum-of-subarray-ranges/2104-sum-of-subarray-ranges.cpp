class Solution {
public:
    void findnse(vector<int>&nums,vector<int>&nse){
        stack<int>st;
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())nse.push_back(nums.size());
            else nse.push_back(st.top());
            st.push(i);
        }
        reverse(nse.begin(),nse.end());
    }
    void findnge(vector<int>&nums,vector<int>&nge){
        stack<int>st;
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty())nge.push_back(nums.size());
            else nge.push_back(st.top());
            st.push(i);
        }
        reverse(nge.begin(),nge.end());
    } 
    void findpse(vector<int>&nums,vector<int>&pse){
        stack<int>st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty())pse.push_back(-1);
            else pse.push_back(st.top());
            st.push(i);
        }
    }
    void findpge(vector<int>&nums,vector<int>&pge){
        stack<int>st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty())pge.push_back(-1);
            else pge.push_back(st.top());
            st.push(i);
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int>nse;
        vector<int>pse;
        vector<int>nge;
        vector<int>pge;
        findnse(nums,nse);
        findpse(nums,pse);
        findnge(nums,nge);
        findpge(nums,pge);
        long long smallest=0;
        long long largest=0;
        for(int i=0; i<nums.size(); i++){
            int l1=i-pse[i];
            int r1=nse[i]-i;
            smallest+=(1LL*l1*r1*nums[i]);
            int l2=i-pge[i];
            int r2=nge[i]-i;
            largest+=(1LL*l2*r2*nums[i]);
        }
        return largest-smallest;
    }
};