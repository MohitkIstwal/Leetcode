class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        //brute approach
        long long ans=0;
        for(int i=0;i<v.size();i++){
            long long mini=v[i],maxi=v[i];
            for(int j=i;j<v.size();j++){
                mini=min(mini,1ll*v[j]);
                maxi=max(maxi,1ll*v[j]);
                ans+=maxi-mini;
            }
        }
        return ans;
    }
};