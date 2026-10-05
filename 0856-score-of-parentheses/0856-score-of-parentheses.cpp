class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=0;
        long long ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                n++;
            }
            else if(s[i]==')'){
                n--;
                if(s[i-1]=='('){
                    ans+=(1<<n);
                }
            }
        }
        return ans;
    }
};