class Solution {
public:

    vector<int> nse(vector<int> &v){
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

    vector<int> pse(vector<int> &v){
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

    int helper(vector<int> &v){
        vector<int> next=nse(v),prev=pse(v);
        int ans=INT_MIN;
        for(int i=0;i<v.size();i++){
            int a=next[i]-1,b=prev[i]+1;
            int temp=(a-b+1)*v[i];
            ans=max(ans,temp);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& v) {
        // same as of the largest histogram one
        int n=v.size(),m=v[0].size();
        vector<vector<int>> psum(n,vector<int> (m));
        int sum=0;
        for(int i=0;i<m;i++){
            sum=0;
            for(int j=0;j<n;j++){
                sum+=(v[j][i]-'0');
                if(v[j][i]=='0'){
                    sum=0;
                }
                psum[j][i]=sum;
            }
        }
        int fans=INT_MIN;
        for(int i=0;i<n;i++){
            int a=helper(psum[i]);
            fans=max(fans,a);
            //cout<<a<<" ";
        }
        return fans;
    }
};