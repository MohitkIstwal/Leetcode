class Solution {
public:

    // just brute force all the possibilties 
    // calculate full sum of grid and then just check row by row and column by column
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> r(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            long long tsum=0;
            for(int j=0;j<m;j++){
                tsum+=grid[i][j];
                sum+=grid[i][j];
            }
            r[i]=tsum;
        }
        long long a=0;
        for(int i=0;i<n;i++){
            a+=r[i];
            if(a*2==sum){
                return true;
            }
            else if(a*2>sum){
                break;
            }
        }
        vector<int> c(m);
        for(int i=0;i<m;i++){
            long long tsum=0;
            for(int j=0;j<n;j++){
                tsum+=grid[j][i];
                //sum+=grid[i][j];
            }
            c[i]=tsum;
        }
        a=0;
        for(int i=0;i<m;i++){
            a+=c[i];
            if(a*2==sum){
                return true;
            }
            else if(a*2>sum){
                break;
            }
        }
        return false;
    }
};