class Solution {
public:
    long long sumAndMultiply(int n) {
        string r=to_string(n),s="";
        for(int i=0;i<r.size();i++){
            if(r[i]!='0'){
                s.push_back(r[i]);
            }
        }
        long long ans;
        if(!s.empty()) ans=stoll(s);
        else return 0;
        long long c=0;
        long long ans1=ans;
        while(ans1!=0){
            c+=ans1%10;
            ans1/=10;
        }
        long long fans=c*ans;
        return fans;
    }
};