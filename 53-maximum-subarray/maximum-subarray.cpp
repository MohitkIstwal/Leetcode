class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=-1e9,maxsum=cursum,n=nums.size();
        for(int i=0;i<n;i++){
            cursum=max(nums[i],cursum+nums[i]);
            maxsum=max(maxsum,cursum);
        }
        return maxsum;
    }
};