class Solution {
public:
    //TC- O(n) ans SC- O(1)
    int maxSumDivThree(vector<int>& nums) {
        int ans=0;
        int a1,b1,a2,b2;
        a1=b1=a2=b2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            if(nums[i]%3==1){
                if(nums[i]<=a1){
                    b1=a1;
                    a1=nums[i];
                }
                else if(nums[i]<b1){
                    b1=nums[i];
                }
            }
            else if(nums[i]%3==2){
                if(nums[i]<=a2){
                    b2=a2;
                    a2=nums[i];
                }
                else if(nums[i]<b2){
                    b2=nums[i];
                }
            }
        }
        if(ans%3==0){
            return ans;
        }
        if(ans%3==1){
            int ans1=-1,ans2=-1;
            if(a1!=INT_MAX) ans1=ans-a1;
            if(a2!=INT_MAX && b2!=INT_MAX) ans2=ans-a2-b2;
            return max(ans1,ans2);
        }
        int ans1=-1,ans2=-1;
        
        if(a2!=INT_MAX) ans1=ans-a2;
        if(a1!=INT_MAX && b1!=INT_MAX) ans2=ans-a1-b1;
       
        return max(ans1,ans2);
    }
};