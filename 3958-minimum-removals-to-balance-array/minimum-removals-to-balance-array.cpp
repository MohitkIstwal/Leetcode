class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans=1e9;
        for(int i=0;i<nums.size();i++){
            long long a=nums[i];
            long long b=a*k;
            auto it=upper_bound(nums.begin(),nums.end(),b)-nums.begin();
            cout<<it<<" ";
            long long temp=0; temp+=i;
            temp+=(nums.size()-it);
            ans=min(ans,temp);
        }
        return (int)ans;
    }
};