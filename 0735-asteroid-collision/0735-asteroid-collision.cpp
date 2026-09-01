class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int i=0; i<asteroids.size(); i++){
            bool flag=false;
            if(asteroids[i]>0){
                st.push(asteroids[i]);
                }
            else{
                flag=true;
                while(!st.empty() && st.top()>0){
                    if(st.top()<abs(asteroids[i])){
                        st.pop();
                    }
                    else if(st.top()==abs(asteroids[i])){
                        flag=false;
                        st.pop();
                        break;
                    }
                    else {
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};