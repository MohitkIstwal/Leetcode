class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<int> sufmin(nums.size());
        int mmin=nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--){
            sufmin[i]=mmin;
            mmin=min(mmin,nums[i]);
            //sufmin[i]=mmin;
        }
        long long ans=-1e18,sum=0;
        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[i];
            long long a=sum-sufmin[i];
            if(a>ans){
                ans=a;
            }
        }
        return ans;
    }
};