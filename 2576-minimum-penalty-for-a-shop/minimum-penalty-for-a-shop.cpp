class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size(),c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='Y'){
                c++;
            }
        }
        int mmin=c,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='Y'){
                c--;
            }
            else{
                c++;
            }
            if(mmin>c){
                c=mmin;
                ans=i+1;
            }
        }
        return ans;
    }
};