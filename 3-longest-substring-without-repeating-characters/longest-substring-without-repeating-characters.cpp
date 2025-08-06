class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        int l=0,r=0,ans=-1;
        map<char,int> mp;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};