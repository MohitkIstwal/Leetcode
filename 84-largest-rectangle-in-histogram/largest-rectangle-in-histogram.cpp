class Solution {
public:

    vector<int> nge(vector<int> &v){
        stack<int> st;
        vector<int> ans(v.size(),v.size());
        for(int i=v.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && v[st.top()]>=v[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans[i]=st.top();
                    st.push(i);
                }
            }
        }
        return ans;
    }

    vector<int> pge(vector<int> &v){
        stack<int> st;
        vector<int> ans(v.size(),-1);
        for(int i=0;i<v.size();i++){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && v[st.top()]>=v[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans[i]=st.top();
                    st.push(i);
                }
            }
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& v) {
        vector<int> pre=pge(v),next=nge(v);
        int ans=0,fans=INT_MIN;
        for(int i=0;i<v.size();i++){
            int a=pre[i]+1,b=next[i]-1;
            ans=b-a+1;
            ans*=v[i];
            fans=max(ans,fans);
        }
        return fans;
    }
};