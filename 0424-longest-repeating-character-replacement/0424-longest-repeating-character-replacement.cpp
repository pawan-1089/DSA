class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0;
        int maxlen=0;
        int len=0;
        int l=0;
        int r=0;
        vector<int>hash(26,0);
        while(r<s.length()){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            while((r-l+1)-maxf>k){
                hash[s[l]-'A']--;
                maxf=0;
                for(int i=0; i<26; i++){
                    maxf=max(maxf,hash[i]);
                }
                l++;
            }
            len=r-l+1;
            if(len-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};