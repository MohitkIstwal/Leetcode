class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(char ch: t){
            mp[ch]++;
        }
        int l=0,r=0,ans=1e9,si=-1,count=0;
        while(r<s.size()){
            if(mp[s[r]]>0){
                count++;
            }
            mp[s[r]]--;
            while(count==t.size()){
                if(r-l+1<ans){
                    ans=r-l+1;
                    si=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    count--;
                }
                l++;
            }
            r++;
        }
        string fans="";
        if(si==-1){
            return fans;
        }
        else{
            for(int i=si;i<si+ans;i++){
                fans.push_back(s[i]);
            }
            return fans;
        }
        
    }
};