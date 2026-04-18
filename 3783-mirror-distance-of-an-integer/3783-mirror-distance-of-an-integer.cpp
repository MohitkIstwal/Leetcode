class Solution {
public:
    int mirrorDistance(int n) {
        string s = "";
        int a = n;

        while(a){
            int x = a % 10;
            char ch = '0' + x;   // ✅ FIX
            s += ch;
            a /= 10;
        }

        //reverse(s.begin(), s.end());
        int b = stoi(s);

        return abs(n - b);
    }
};