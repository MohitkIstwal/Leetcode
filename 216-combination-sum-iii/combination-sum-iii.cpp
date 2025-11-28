class Solution {
public:
    //first f() start from 1
    //if sum==0 and ds size==k then put in ans ds
    // if arr[i]>sum then break
    // next transition state of recursion will be f(ind+1,sum-ind,)
    // now just implement this idea

    void helper(int ind,int n,int k,vector<int> &v,vector<vector<int>> &ans){
        if(n==0 && v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<10;i++){
            if(n>=i){
                v.push_back(i);
                helper(i+1,n-i,k,v,ans);
                v.pop_back();
            }
            else{
                break;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> ans;
        helper(1,n,k,v,ans);
        return ans;
    }
};