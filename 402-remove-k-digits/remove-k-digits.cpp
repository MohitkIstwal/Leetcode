class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        if(k==n){
            return "0";
        }
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(num[i]);
            }
            else{
                while(!st.empty() && k && st.top()>num[i]){
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        while(k--){
            st.pop();
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        bool bl=false;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]=='0'){
                ans.pop_back();
            }
            else{
                bl=true;
                break;
            }
        }
        if(bl){
            reverse(ans.begin(),ans.end());
            return ans;
        }
        else{
            return "0";
        }
    }
};