class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        long long area=0;
        long long ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>presum(n,vector<int>(m,0));
        for(int i=0; i<m; i++){
            int sum=0;
            for(int j=0; j<n; j++){
                sum+=matrix[j][i]-'0';
                if(matrix[j][i]=='0'){
                    sum=0;
                }
                presum[j][i]=sum;
            }
        }
        for(int i=0; i<n; i++){
            stack<int>st;
            //computer each row like histogram
            for(int j=0; j<m; j++){
                while(!st.empty() && presum[i][st.top()]>presum[i][j]){
                    int el=st.top();
                    st.pop();
                    int nse=j;
                    int pse=st.empty()?-1:st.top();
                    area=1LL*presum[i][el]*(nse-pse-1);
                    ans=max(ans,area);
                }
                st.push(j);
            }
            while(!st.empty()){
                int el=st.top();
                st.pop();
                int nse=m;
                int pse=st.empty()?-1:st.top();
                area=1LL*presum[i][el]*(nse-pse-1);
                ans=max(ans,area);
            }
        }
        return ans;
    }
};