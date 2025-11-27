class Solution {
public:
    //brute approach will be to generate all in a set and then put in vector for ans

    void helper(int id,vector<int> &nums,vector<int> &v,set<vector<int>> &st){
        if(id==nums.size()){
            st.insert(v);
            return;
        }

        v.push_back(nums[id]);
        helper(id+1,nums,v,st);
        v.pop_back();
        helper(id+1,nums,v,st);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        set<vector<int>> st;
        helper(0,nums,v,st);
        vector<vector<int>> ans;
        for(auto vec: st){
            ans.push_back(vec);
        }
        return ans;
    }
};