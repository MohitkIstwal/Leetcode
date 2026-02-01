class Solution {
public:
    int countMonobit(int n) {
        n++;
        int ans=0;
        while(n!=0){
            n/=2;
            ans++;
        }
        return ans;
    }
};