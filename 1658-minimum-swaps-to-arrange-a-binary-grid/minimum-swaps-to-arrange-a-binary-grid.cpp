class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> zeroes;
        for(int i=0;i<grid.size();i++){
            int cnt=0;
            for(int j=grid[0].size()-1;j>=0;j--){
                if(grid[i][j]==0){
                    cnt++;
                }
                else{
                    break;
                }
            }
            zeroes.push_back(cnt);
        }
        int ans=0;
        for(int i=0;i<zeroes.size();i++){
            int target=zeroes.size()-i-1;
            int ind=-1;
            for(int j=i;j<zeroes.size();j++){
                if(zeroes[j]>=target){
                    ind=j;
                    break;
                }
            }
            if(ind==-1){
                return -1;
            }
            ans+=(ind-i);
            int k=zeroes[ind];
            for(int j=ind;j>i;j--){
                zeroes[j]=zeroes[j-1];
            }
            zeroes[i]=k;
        }
        return ans;
    }
};