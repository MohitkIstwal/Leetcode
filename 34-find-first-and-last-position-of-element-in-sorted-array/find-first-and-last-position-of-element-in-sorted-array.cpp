class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if(nums.size()==0){
            v.push_back(-1); v.push_back(-1);
            return v;
        }
        auto it=lower_bound(nums.begin(),nums.end(),target);
        int b=it-nums.begin();
        if(b!=nums.size() && nums[b]==target){
            v.push_back(b);
        }
        else{
            v.push_back(-1);
        }
        it=upper_bound(nums.begin(),nums.end(),target);
        int a=it-nums.begin()-1;
        if(a!=-1 && nums[a]==target){
            v.push_back(a);
        }
        else{
            v.push_back(-1);
        }
        return v;
    }
};