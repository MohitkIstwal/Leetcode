class Solution {
public:

    int helper(vector<int> v,int k){
        map<int,int> mp;
        int l=0,r=0,ans=0;
        while(r<v.size()){
            mp[v[r]]++;
            while(mp.size()>k){
                mp[v[l]]--;
                if(mp[v[l]]==0){
                    mp.erase(v[l]);
                }
                l++;
            }
            if(mp.size()<=k){
                ans+=(r-l+1);
            }
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};