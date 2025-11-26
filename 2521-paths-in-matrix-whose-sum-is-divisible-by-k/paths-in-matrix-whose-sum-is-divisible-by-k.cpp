class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        // dp[i][j][r] = number of ways to reach cell (i,j) with sum % k = r
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        // Base case: start at (0,0)
        int rem = grid[0][0] % k;
        dp[0][0][rem] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int r = 0; r < k; r++) {

                    if (dp[i][j][r] == 0) continue;  
                    // no ways reaching here with this remainder → skip

                    // Move DOWN: (i+1, j)
                    if (i + 1 < m) {
                        int new_rem = (r + grid[i + 1][j]) % k;
                        dp[i + 1][j][new_rem] =
                            (dp[i + 1][j][new_rem] + dp[i][j][r]) % MOD;
                    }

                    // Move RIGHT: (i, j+1)
                    if (j + 1 < n) {
                        int new_rem = (r + grid[i][j + 1]) % k;
                        dp[i][j + 1][new_rem] =
                            (dp[i][j + 1][new_rem] + dp[i][j][r]) % MOD;
                    }

                }
            }
        }

        // We want sum % k == 0 at the bottom-right corner
        return dp[m-1][n-1][0];
    }
};
