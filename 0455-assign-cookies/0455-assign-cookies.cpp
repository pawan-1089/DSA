class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        int cnt=0;
        int n=s.size();
        for(int i=0; i<g.size(); i++){
            if(j==n)break;
            while(j<n && s[j]<g[i]){
                j++;
            }
            if(j<n && s[j]>=g[i]){
                cnt++;
                j++;
            }
        }
        return cnt;
    }
};