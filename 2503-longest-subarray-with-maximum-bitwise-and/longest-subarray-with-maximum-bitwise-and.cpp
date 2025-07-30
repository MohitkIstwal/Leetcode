class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a=*max_element(nums.begin(),nums.end());
        int ans=0,m=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a){
                ans++;
            }
            else{
                ans=0;
            }
            m=max(ans,m);
        }
        return m;
    }
};