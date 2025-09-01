class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
       int n=nums2.size();
       vector<int> ans(n,-1);
       stack<int> st;
       for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && nums2[i]>st.top()){
                    st.pop();
                }
                if(st.empty()){
                    st.push(nums2[i]);
                }
                else{
                    ans[i]=st.top();
                    st.push(nums2[i]);
                }
            }
       }
       vector<int> fans(nums1.size());
       for(int i=0;i<nums1.size();i++){
            fans[i]=ans[mp[nums1[i]]];
       }
       return fans;
    }
};