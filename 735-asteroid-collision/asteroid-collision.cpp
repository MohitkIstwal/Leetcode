class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> st;
        for(int i=0;i<v.size();i++){
            bool bl=false;

            while(!st.empty() && st.top()>0 && v[i]<0){
                if(abs(st.top())<abs(v[i])){
                    st.pop(); continue;
                }
                else if(abs(st.top())==abs(v[i])){
                    st.pop();
                }
                bl=true; break;
            }

            if(!bl){
                st.push(v[i]);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};