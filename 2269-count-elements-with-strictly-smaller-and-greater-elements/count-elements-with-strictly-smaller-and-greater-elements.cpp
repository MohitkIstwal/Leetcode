class Solution {
public:
    int countElements(vector<int>& nums) {
        int mmin=*min_element(nums.begin(),nums.end()),mmax=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mmin && nums[i]<mmax){
                ans++;
            }
        }
        return ans;
    }
};