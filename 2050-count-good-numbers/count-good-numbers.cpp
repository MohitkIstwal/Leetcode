class Solution {
public:

    long long getpower(long long n,long long x){
        long long mod=1e9+7;
        if(x==1){
            return n;
        }
        long long ans=1;
        while(x>0){
            if(x&1){
                ans=(ans*n)%mod;
            }
            n=(n*n)%mod;
            x/=2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        int mod=1e9+7;
        long long a=n/2,b=n/2;
        if(n&1){
            a++;
        }
        long long x=getpower(5,a);
        long long y=getpower(4,b);
        long long k=x*y;
        return (x*y)%mod;
    }
};