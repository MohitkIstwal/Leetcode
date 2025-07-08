class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> p;
        for(int i=0;i<nums.size();i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());
        vector<int> ans;
        int r=nums.size()-1,l=0;
        while(l<r){
            if(p[l].first+p[r].first==target){
                ans.push_back(p[l].second);
                ans.push_back(p[r].second);
                return ans;
            }
            else{
                if(p[l].first+p[r].first<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};