class Solution {
public:
    int mirrorFrequency(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(auto it: mp){
            char ch=it.first,mirrorch;
            if(ch>='0' && ch<='9'){
                mirrorch='9'+'0'-ch;
            }
            else{
                mirrorch='a'+'z'-ch;
            }
            ans+=abs(mp[ch]-mp[mirrorch]);
            mp[ch]=0; mp[mirrorch]=0;
        }
        return ans;
    }
};