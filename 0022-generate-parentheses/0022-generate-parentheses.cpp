class Solution {
public:
    void f(int n,int open,int close,string str,vector<string>&ans){
        if(str.size()==2*n){
            ans.push_back(str);
            return ;
        }
        if(open<n){
            f(n,open+1,close,str+'(',ans);
        }
        if(open>close){
            f(n,open,close+1,str+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string>ans;
        f(n,open,close,"",ans);
        return ans;
    }
};