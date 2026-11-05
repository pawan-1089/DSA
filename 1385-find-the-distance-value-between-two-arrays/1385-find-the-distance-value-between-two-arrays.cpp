class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort(arr1.begin(),arr1.end());
        // sort(arr2.begin(),arr2.end());
        int n=arr1.size();
        int m=arr2.size();
        int cnt=0;
        // int j=0;
        int i=0;
        while(i<n){
            bool flag=true;
            int j=0;
            while(j<m){
                if(abs(arr1[i]-arr2[j])<=d){
                    flag=false;
                    j=0;
                    break;
                }
                j++;
            }
            if(flag==true)cnt++;
            i++;
        }
        return cnt;
    }
};