class Solution {
public:
    int maxBottlesDrunk(int n, int k) {
        // easy peasy lemon squeezy (-:
        int ans=0;
        while(n>=k){
            ans+=k;
            n-=(k-1);
            k++;
        }
        ans+=n;
        return ans;
    }
};