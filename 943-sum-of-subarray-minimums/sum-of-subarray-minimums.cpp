class Solution {
public:

    vector<int> nse(vector<int> &arr){
        vector<int> v(arr.size(),arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && arr[i]<arr[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                }
                else{
                    v[i]=st.top();
                    st.push(i);
                }
            }
        }
        return v;
    }

    vector<int> psee(vector<int> &arr){
        vector<int> v(arr.size(),-1);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && arr[i]<=arr[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                }
                else{
                    v[i]=st.top();
                    st.push(i);
                }
            }
        }
        return v;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pre=psee(arr),nex=nse(arr);
        long long total=0,mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            int a=i-pre[i],b=nex[i]-i;
            total= (total + (arr[i] * a % mod) * b % mod) % mod;       
        }
        return (int)total;
    }
};