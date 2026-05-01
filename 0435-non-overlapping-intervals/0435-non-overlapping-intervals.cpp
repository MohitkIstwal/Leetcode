class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int start=v[0][0],end=v[0][1];
        int ans=0;
        for(int i=1;i<v.size();i++){
            if(v[i][0]>=end){
                start=v[i][0];
                end=v[i][1];
            }
            else{
                ans++;
                end=min(end,v[i][1]);
            }
        }
        return ans;
    }
};