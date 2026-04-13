class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mmin=1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                mmin=min(mmin,abs(i-start));
            }
        }
        return mmin;
    }
};