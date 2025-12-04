class Solution {
public:
    int countCollisions(string str) {
        int r,l,s;
        l=r=s=0;
        bool R=false,S=false;
        int ans=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='R'){
                r++;
                R=true;
            }
            if(str[i]=='L' && (R || S)){
                if(r){
                    ans+=r+1;
                    r=0;
                }
                else l++;
            }
            if(str[i]=='S'){
                S=true;
                ans+=r;
                r=0;
            }
        }
        ans+=l;
        return ans;
    }
};