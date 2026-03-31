class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        vector<char> ans(len, '?');

        // Step 1: Apply all 'T' constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != '?' && ans[i + j] != str2[j]) {
                        return "";
                    }
                    ans[i + j] = str2[j];
                }
            }
        }

        // Step 2: Fill remaining with 'a'
        for (int i = 0; i < len; i++) {
            if (ans[i] == '?') ans[i] = 'a';
        }

        // Step 3: Fix 'F' constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                // check if substring equals str2
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool fixed = false;

                    // try to break from rightmost
                    for (int j = m - 1; j >= 0 && !fixed; j--) {
                        char original = ans[i + j];

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == original) continue;

                            ans[i + j] = c;

                            // check all 'T' still valid
                            bool ok = true;
                            for (int k = 0; k < n && ok; k++) {
                                if (str1[k] == 'T') {
                                    for (int x = 0; x < m; x++) {
                                        if (ans[k + x] != str2[x]) {
                                            ok = false;
                                            break;
                                        }
                                    }
                                }
                            }

                            if (ok) {
                                fixed = true;
                                break;
                            }
                        }

                        if (!fixed) ans[i + j] = original;
                    }

                    if (!fixed) return "";
                }
            }
        }

        return string(ans.begin(), ans.end());
    }
};