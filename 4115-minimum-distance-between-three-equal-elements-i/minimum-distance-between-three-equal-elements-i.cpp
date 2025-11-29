class Solution {
public:
    int minimumDistance(vector<int>& v) {
        int ans=1e9,n=v.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(v[i]==v[j] && v[j]==v[k] && v[k]==v[i]){
                        ans=min(ans,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }
        if(ans==1e9){
            ans=-1;
        }
        return ans;
    }
};