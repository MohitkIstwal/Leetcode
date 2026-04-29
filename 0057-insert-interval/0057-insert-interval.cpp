class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newi) {
        int start=newi[0],end=newi[1];
        vector<vector<int>> ans;
        int a=start,b=end; 
        bool bl=1;
        for(int i=0;i<v.size();i++){
            if(start>v[i][1]){
                ans.push_back(v[i]);
            }
            else if(v[i][0]<=end){
                a=min(a,v[i][0]);
                b=max(b,v[i][1]);
            }
            else{
                if(bl){
                    ans.push_back({a,b});
                    bl=0;
                }
                ans.push_back(v[i]);
            }
        }
        if(bl){
            ans.push_back({a,b});
            bl=0;
        }
        return ans;
    }
};