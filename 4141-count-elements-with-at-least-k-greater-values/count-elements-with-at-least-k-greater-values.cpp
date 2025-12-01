class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k==0){
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int a=nums.size()-k,ans=-1;
        for(int i=0;i<a;i++){
            if(i+1<nums.size() && nums[i+1]>nums[i]){
                ans=i;
            }
        }
        return ans+1;
    }
};