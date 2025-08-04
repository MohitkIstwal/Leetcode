class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,ans=-1;
        map<int,int> mp;
        while(r<fruits.size()){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                    l++;
                    break;
                }
                l++;
            }
            ans=max(r-l+1,ans);
            r++;
        }
        return ans;
    }
};