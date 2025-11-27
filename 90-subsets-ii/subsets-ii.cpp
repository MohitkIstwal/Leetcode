class Solution {
public:

    // the optimal approach is similar to sum2 one
    // we will traverse through the arr and make sure that in level same type of element is not added

    void helper(int ind,vector<int> &nums,vector<int> &v,vector<vector<int>> &ans){
        ans.push_back(v);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            helper(i+1,nums,v,ans);
            v.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        vector<vector<int>> ans;
        helper(0,nums,v,ans);
        return ans;
    }
};