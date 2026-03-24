class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        
        int size = n * m;
        vector<int> arr(size);
        
        // Flatten
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[k++] = grid[i][j];
            }
        }
        
        vector<int> prefix(size, 1), suffix(size, 1);
        
        // Prefix
        for(int i = 1; i < size; i++) {
            long long val = 1LL * prefix[i-1] * arr[i-1];
            prefix[i] = val % mod;
        }
        
        // Suffix
        for(int i = size - 2; i >= 0; i--) {
            long long val = 1LL * suffix[i+1] * arr[i+1];
            suffix[i] = val % mod;
        }
        
        // Result
        vector<vector<int>> res(n, vector<int>(m));
        
        k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                long long val = 1LL * prefix[k] * suffix[k];
                res[i][j] = val % mod;
                k++;
            }
        }
        
        return res;
    }
};