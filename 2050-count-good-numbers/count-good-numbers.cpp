class Solution {
public:

    int mod=1e9+7;

    long long even(long long n){
        if(n==0){
            return 1;
        }
        long long ee=even(n/2);

        if(n&1){
            return (ee*ee*5)%mod;
        }
        else{
            return (ee*ee)%mod;
        }
    }

    long long odd(long long n){
        if(n==0){
            return 1;
        }
        long long oo=odd(n/2);

        if(n&1){
            return (oo*oo*4)%mod;
        }
        else{
            return (oo*oo)%mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long a=even((n+1)/2);
        long long b=odd(n/2);
        long long ans=(a*b)%mod;
        return (int)ans;
    }
};