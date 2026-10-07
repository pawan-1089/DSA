class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mpp;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){
                mpp[5]++;
            }
            else if(bills[i]==10){
                mpp[10]++;
                if(mpp.find(5)==mpp.end()){
                    return false;
                }
                else {
                    mpp[5]--;
                    if(mpp[5]==0){
                        mpp.erase(5);
                    }
                }
            }
            else if(bills[i]==20){
                if(mpp.find(5)==mpp.end()){
                    return false;
                }
                else {
                    mpp[5]--;
                    if(mpp[5]==0){
                        mpp.erase(5);
                    }
                    if(mpp.find(10)!=mpp.end()){
                        mpp[10]--;
                        if(mpp[10]==0)mpp.erase(10);
                    }
                    else {
                        if(mpp[5]>=2){
                            mpp[5]=mpp[5]-2;
                            if(mpp[5]==0){
                            mpp.erase(5);
                            }
                        }
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};