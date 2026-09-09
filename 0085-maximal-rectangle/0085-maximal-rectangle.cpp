class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        long long area = 0;
        long long ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>height(m,0);
        for (int i = 0; i<n; i++) {
            for (int j = 0; j <m; j++) {
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else height[j]=0;
            }
            stack<int> st;
            // computer each row like histogram
            for (int j = 0; j < m; j++) {
                while (!st.empty() && height[st.top()] > height[j]) {
                    int el = st.top();
                    st.pop();
                    int nse = j;
                    int pse = st.empty() ? -1 : st.top();
                    area = 1LL * height[el]*(nse - pse - 1);
                    ans = max(ans, area);
                }
                st.push(j);
            }
            while (!st.empty()) {
                int el = st.top();
                st.pop();
                int nse = m;
                int pse = st.empty() ? -1 : st.top();
                area = 1LL * height[el]*(nse - pse - 1);
                ans = max(ans, area);
            }
        }
        return ans;
    }
};