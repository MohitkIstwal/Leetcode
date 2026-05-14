class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i+1!=nums[i] && i!=nums.size()-1){
                return false;
            }
            if(i==nums.size()-1){
                if(i!=nums[i]){
                    return false;
                }
            }
        }
        return true;
    }
};