class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i=0;i<nums.size()-2;i++){
            if (i>0 && nums[i]==nums[i - 1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int s=nums[i]+nums[l]+nums[r];
                if(s==0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    st.insert(temp);
                    l++; r--;
                }
                else if(s<0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};