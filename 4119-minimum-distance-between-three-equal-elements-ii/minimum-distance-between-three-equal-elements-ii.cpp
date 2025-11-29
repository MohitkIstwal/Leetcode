class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if(nums.size()<3){
            return -1;
        }
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        } 
        sort(v.begin(),v.end());
        int ans=1e9;
        for(int i=0;i<v.size()-2;i++){
            if(i+2<v.size() && v[i].first==v[i+2].first){
                ans=min(ans,2*(v[i+2].second-v[i].second));
            }
        }
        if(ans==1e9){
            ans=-1;
        }
        return ans;
    }
};