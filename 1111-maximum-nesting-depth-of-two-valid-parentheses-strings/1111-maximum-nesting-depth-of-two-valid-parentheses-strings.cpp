class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int depth=0;
        string g1="";
        string g2="";
        vector<int>t1;
        for(int i=0; i<n; i++){
            if(seq[i]=='('){
                depth++;
                if(depth%2==1){
                    t1.push_back(0);
                }
                else t1.push_back(1);
            }
            else if(seq[i]==')'){
                depth--;
                if(depth%2==1){
                    t1.push_back(1);
                }
                else t1.push_back(0);
            }
        }
        return t1;
    }
};