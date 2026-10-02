class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        unordered_map<char,int>mpp;
        mpp['a']=-1;
        mpp['b']=-1;
        mpp['c']=-1;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]=i;
            if(mpp.find(-1)==mpp.end()){
                int mini=s.size();
                for(auto it:mpp){
                    if(it.second<mini){
                        mini=it.second;
                    }
                }
                ans=ans+mini+1;
            }
        }
        return ans;
    }
};