class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long negative=0,mmin=1e9,sum=0;
        for(auto v: matrix){
            for(int val: v){
                if(val<0){
                    negative++;
                }
                sum+=abs(val);
                mmin=min(mmin,1ll*abs(val));
            }
        }
        if(negative&1){
            sum-=2*mmin;
        }
        return (long long)sum;
    }
};