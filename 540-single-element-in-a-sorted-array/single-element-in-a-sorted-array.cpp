class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        int l=1,r=n-2;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]){
                return nums[m];
            }
            else{
                if(m%2==0){
                    if(nums[m]==nums[m+1]){
                        l=m+1;
                    }
                    else{
                        r=m-1;
                    }
                }
                else{
                    if(nums[m]==nums[m-1]){
                        l=m+1;
                    }
                    else{
                        r=m-1;
                    }
                }
            }
        }
        return 0;
    }
};