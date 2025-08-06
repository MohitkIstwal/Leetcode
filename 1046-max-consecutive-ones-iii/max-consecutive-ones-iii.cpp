class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,ans=-1,a=0;
        while(r<nums.size()){
            if(nums[r]==0){a++;}
            while(a>k){
                if(nums[l]==0){
                    a--; l++; break;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};