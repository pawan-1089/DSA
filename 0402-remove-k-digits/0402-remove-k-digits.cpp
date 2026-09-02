class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int cnt=0;
        for(int i=0; i<num.length(); i++){
            while(!st.empty()&& k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty())return "0";
        string s;
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.length() && s[i]=='0'){
            i++;
        }
        if(i==s.length())return "0";
        return s.substr(i);

    }
};