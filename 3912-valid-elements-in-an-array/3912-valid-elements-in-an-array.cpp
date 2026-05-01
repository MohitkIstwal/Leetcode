class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        if(nums.size()<3){
            return nums;
        }
        vector<int> ans(nums.size(),0);
        ans[0]=1;
        ans[ans.size()-1]=1;
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>maxi){
                ans[i]=1;
            }
            maxi=max(maxi,nums[i]);
        }
        maxi=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>maxi){
                ans[i]=1;
            }
            maxi=max(maxi,nums[i]);
        }
        vector<int> v;
        for(int i=0;i<ans.size();i++){
            //cout<<ans[i]<<" ";
            if(ans[i]){
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};