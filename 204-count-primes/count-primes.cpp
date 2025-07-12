class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<int> isprime(n,1);
        for(int i=2;i*i<n;i++){
            if(isprime[i]==1){
                for(int j=i*i;j<n;j+=i){
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