class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            stack<int> st;
            for(int j=0;j<nums2.size();j++){
                st.push(nums2[j]);
            }
            int a=nums1[i],b=-1;
            while(st.top()!=a && !st.empty()){
                if(st.top()>a){
                    b=st.top();
                }
                st.pop();
            }
            ans[i]=b;
        }
        return ans;
    }
};