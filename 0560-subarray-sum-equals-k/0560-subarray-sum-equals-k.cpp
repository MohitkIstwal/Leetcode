class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> presum(nums.size()+1);
        presum[0]=0;
        map<int,int> mp; int ans=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            presum[i+1]=presum[i]+nums[i];
            mp[presum[i+1]]++;
            int a=presum[i+1]-k;
            if(k==0){
                ans+=max(0,mp[a]-1);
            }
            else ans+=mp[a];
        }
        return ans;
    }
};