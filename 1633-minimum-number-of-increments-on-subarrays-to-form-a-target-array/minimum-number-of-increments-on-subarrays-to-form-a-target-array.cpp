class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        int ans=v[0];
        for(int i=0;i<v.size()-1;i++){
            ans+=max(v[i+1]-v[i],0);
        }
        return ans;
    }
};