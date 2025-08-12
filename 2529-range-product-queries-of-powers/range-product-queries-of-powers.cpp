class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> v;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                v.push_back(1<<i);
            }
        }
        vector<int> fans; int mod=1e9+7;
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0],b=queries[i][1];
            long long ans=1;
            for(int j=a;j<=b;j++){
                ans=((ans%mod)*(v[j]%mod))%mod;
            }
            fans.push_back((int)ans);
        }
        return fans;
    }
};