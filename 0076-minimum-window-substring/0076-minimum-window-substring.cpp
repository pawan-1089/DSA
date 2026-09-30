class Solution {
public:
    string minWindow(string s, string t) {
        int r=0;
        int l=0;
        int minlen=INT_MAX;
        int startIdx=-1;
        string ans="";
        vector<int>hash(256,0);
        for(auto ch:t){
            hash[ch]++;
        }
        int cnt=0;
        while(r<s.size()){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==t.size()){
                if((r-l+1)<minlen){
                    minlen=r-l+1;
                    startIdx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt=cnt-1;
                l++;
            }
            r++;
        }
        if(startIdx==-1){
            return "";
        }
        ans=s.substr(startIdx,minlen);
        return ans;
    }
};