class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int total = 1 << k;   // 2^k

        // Early pruning
        if (n < k + total - 1) return false;

        vector<bool> seen(total, false);
        int mask = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            // Shift left and add current bit
            mask = ((mask << 1) & (total - 1)) | (s[i] - '0');

            // Start checking only after first k chars
            if (i >= k - 1) {
                if (!seen[mask]) {
                    seen[mask] = true;
                    cnt++;
                    if (cnt == total) return true;
                }
            }
        }
        return false;
    }
};