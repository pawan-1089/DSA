class Solution {
public:
    int minAddToMakeValid(string s) {
        int req=0;
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(')st.push('(');
            else {
                if(st.empty()){
                    req++;
                }
                else {
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            req++;
            st.pop();
        }
        return req;
    }
};