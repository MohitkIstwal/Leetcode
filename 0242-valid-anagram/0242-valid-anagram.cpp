class Solution {
public:
    bool isAnagram(string s, string r) {
        sort(s.begin(),s.end());
        sort(r.begin(),r.end());
        return s==r;
    }
};