class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int ans=0,fans=0,m=-1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                ans+=v[i];
                m=max(v[i],m);
            }
            else{
                if(ans){
                    ans+=v[i];
                    m=max(v[i],m);
                    fans+=ans-m;
                    ans=0; m=-1;
                }
            }
            
        }
        if(ans){
            ans+=v[s.size()-1];
            m=max(v[s.size()-1],m);
            fans+=ans-m;
            ans=0;
        }
        return fans;
    }
};