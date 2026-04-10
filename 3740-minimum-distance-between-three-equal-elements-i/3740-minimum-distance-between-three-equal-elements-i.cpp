class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=1e9;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k] && nums[k]==nums[i]){
                        ans=min(ans,abs(i - j) + abs(j - k) + abs(k - i));
                    }
                }
            }
        }
        if(ans==1e9) ans=-1;
        return ans;
    }
};