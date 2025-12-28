class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int ans=0;
        for(auto it : v){
            for(auto val: it){
                if(val<0){
                    ans++;
                }
            }
        }
        return ans;
    }
};