class Solution {
public:

    void helper(int ind,int target,vector<int> &candidates,vector<int> temp,vector<vector<int>> &ans){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target-candidates[ind]>=0){
            temp.push_back(candidates[ind]);
            helper(ind,target-candidates[ind],candidates,temp,ans);
            temp.pop_back();   
        }
        helper(ind+1,target,candidates,temp,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0,target,candidates,temp,ans);
        return ans;
    }
};