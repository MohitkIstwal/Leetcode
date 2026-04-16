class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; int ans=0,sum=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mp[sum]++;
            int a=sum-k;
            if(k==0){
                ans+=max(0,mp[a]-1);
            }
            else ans+=mp[a];
        }
        return ans;
    }
};