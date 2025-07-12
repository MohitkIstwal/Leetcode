class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<int> isprime(n,1);
        isprime[0]=isprime[1]=0;
        for(int i=2;i<n;i++){
            if(isprime[i]==1){
                for(int j=2*i;j<n;j+=i){
                    isprime[j]=0;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                 count++;
            }
        }
        return count;
    }
};