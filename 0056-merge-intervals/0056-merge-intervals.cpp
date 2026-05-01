class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
       sort(v.begin(),v.end());
       vector<vector<int>> ans;
       int start=v[0][0],end=v[0][1];
       for(int i=1;i<v.size();i++){
            if(v[i][0]>end){
                ans.push_back({start,end});
                start=v[i][0];
                end=v[i][1];
            }
            else{
                end=max(v[i][1],end);
            }
       }
       ans.push_back({start,end});
       return ans;
    }
};
