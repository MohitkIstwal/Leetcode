class Solution {
public:
    int findFinalValue(vector<int>& v, int a) {
        while(find(v.begin(),v.end(),a)!=v.end()){
            a*=2;
        }
        return a;
    }
};