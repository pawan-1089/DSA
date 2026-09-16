class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int start=0;
        int end=cardPoints.size()-1;
        int maxsum=0;
        int sum=0;
        for(start=0; start<k; start++){
            sum+=cardPoints[start];
        }
        maxsum=sum;
        start=start-1;
        while(start>=0){
            sum-=cardPoints[start];
            sum+=cardPoints[end];
            end--;
            start--;
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};