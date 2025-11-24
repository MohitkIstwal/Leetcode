class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num=0;
        vector<bool> ans(nums.size(),false);
        for(int i=0;i<nums.size();i++){
            num*=2; num+=nums[i];
            num%=5;
            if(num%5==0){
                ans[i]=true;
            }
        }
        return ans;
    }
};