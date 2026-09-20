class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>mpp;
        int n=26;
        for(char i='a'; i<='z'; i++){
            mpp[i]=n;
            n--;
        }
        int ans=0;
        int num=0;
        for(int i=0; i<s.size(); i++){
            num=mpp[s[i]];
            ans=ans+(num*(i+1));
        }
        return ans;
    }
};