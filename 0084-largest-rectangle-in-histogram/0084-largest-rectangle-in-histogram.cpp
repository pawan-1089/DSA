class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        long long ans=0;
        int n=heights.size();
        stack<int>st;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el=st.top();
                st.pop();
                int nse=i;
                int pse= st.empty()?-1:st.top();
                long long area=heights[el]*(nse-pse-1);
                ans=max(ans,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            long long area=heights[el]*(nse-pse-1);
            ans=max(ans,area);
        }
        return ans;
    }
};