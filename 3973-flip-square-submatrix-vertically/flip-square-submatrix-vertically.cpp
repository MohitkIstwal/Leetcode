class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> temp;
        for(int i=x;i<x+k;i++){
            vector<int> v;
            for(int j=y;j<y+k;j++){
                v.push_back(grid[i][j]);
            }
            temp.push_back(v);
        }
        int a=temp.size()-1;
        for(int i=x;i<x+k;i++){
            int b=0;
            for(int j=y;j<y+k;j++){
                grid[i][j]=temp[a][b];
                b++;
            }
            a--;
        }
        return grid;
    }
};