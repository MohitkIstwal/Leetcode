class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=accumulate(batteries.begin(),batteries.end(),0ll);
        long long l=1,r=sum/n;
        while(l<r){
            long long m=(l+r+1)/2,s=0;
            for(int i=0;i<batteries.size();i++){
                s+=min(batteries[i]*1ll,m);
            }
            if(s>=(n*m)){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        return l;
    }
};