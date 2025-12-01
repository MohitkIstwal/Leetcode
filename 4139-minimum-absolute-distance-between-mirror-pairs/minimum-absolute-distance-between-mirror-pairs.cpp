class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int> mp;
        int ans=1e9;
        for(int i=nums.size()-1;i>=0;i--){
            int a=nums[i];
            string s=to_string(a);
            reverse(s.begin(),s.end());
            int b=stoi(s);
            if(mp[b]){
                ans=min(ans,abs(i-mp[b]));
            }
            mp[nums[i]]=i;
        }
        if(ans==1e9) ans=-1;
        return ans;
    }
};