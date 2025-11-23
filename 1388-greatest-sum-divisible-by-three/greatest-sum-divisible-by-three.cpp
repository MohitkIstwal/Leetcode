class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans=0;
        vector<int> arr1,arr2;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            if(nums[i]%3==1){
                arr1.push_back(nums[i]);
            }
            else if(nums[i]%3==2){
                arr2.push_back(nums[i]);
            }
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        if(ans%3==0){
            return ans;
        }
        if(ans%3==1){
            int ans1=-1,ans2=-1;
            if(!arr1.empty()){
                ans1=ans-arr1[0];
            }
            if(arr2.size()>=2){
                ans2=ans-arr2[0]-arr2[1];
            }
            return max(ans1,ans2);
        }
        int ans1=-1,ans2=-1;
        if(!arr2.empty()){
            ans1=ans-arr2[0];
        }
        if(arr1.size()>=2){
            ans2=ans-arr1[0]-arr1[1];
        }
        return max(ans1,ans2);
    }
};