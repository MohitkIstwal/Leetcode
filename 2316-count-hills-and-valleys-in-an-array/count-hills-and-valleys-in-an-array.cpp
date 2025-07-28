class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int f=0,ans=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i] && f==0){
                f=1;
            }
            else if(nums[i+1]<nums[i] && f==0){
                f=2;
            }
            else if(f==1 && nums[i+1]<nums[i]){
                ans++;
                f=2;
            }
            else if(f==2 && nums[i+1]>nums[i]){
                ans++;
                f=1;
            }
        }
        return ans;
    }
};