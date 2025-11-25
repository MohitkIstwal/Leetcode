class Solution {
public:

    void helper(vector<int> &nums,int &n,int ind,vector<vector<int>> &ans,vector<int> &v){
        if(ind==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        helper(nums,n,ind+1,ans,v);

        v.pop_back();
        helper(nums,n,ind+1,ans,v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int ind=0;
        vector<int> v;
        helper(nums,n,ind,ans,v);
        return ans;
    }
};