class Solution {
public:

    void helper(int id,int target,vector<int> &can,vector<int> &v,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(v);
            return;
        }

        for(int i=id;i<can.size();i++){
            if(i>id && can[i]==can[i-1]) continue;
            if(can[i]>target){
                break;
            }
            v.push_back(can[i]);
            helper(i+1,target-can[i],can,v,ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,target,candidates,v,ans);
        return ans;
    }
};