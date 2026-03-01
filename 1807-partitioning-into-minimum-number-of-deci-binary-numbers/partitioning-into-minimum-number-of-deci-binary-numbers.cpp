class Solution {
public:
    int minPartitions(string n) {
        int ans=-1;
        for(char ch: n){
            int x=(int)ch-'0';
            ans=max(ans,x);
        }
        return ans;
    }
};