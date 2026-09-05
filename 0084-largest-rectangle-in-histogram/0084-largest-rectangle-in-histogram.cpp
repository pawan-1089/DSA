class Solution {
public:
    void findnse(vector<int>&nse,vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        for(int i=n-1; i>=0; i--){
             while(!st.empty() &&heights[st.top()]>=heights[i]){
                st.pop();
             }
             if(st.empty())nse.push_back(n);
             else nse.push_back(st.top());
             st.push(i);
        }
        reverse(nse.begin(),nse.end());
    }
    void findpse(vector<int>&pse,vector<int>&heights){
        stack<int>st;
         for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())pse.push_back(-1);
            else pse.push_back(st.top());
            st.push(i);
         }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>pse;
        vector<int>nse;
        findnse(nse,heights);
        findpse(pse,heights);
        long long ans=0;
        for(int i=0; i<heights.size(); i++){
            int width=nse[i]-pse[i]-1;
            int height=heights[i];
            long long area=width*height;
            ans=max(ans,area);
        }
        return ans;
    }
};