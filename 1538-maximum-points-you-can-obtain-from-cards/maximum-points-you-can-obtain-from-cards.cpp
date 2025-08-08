class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n=v.size();
        if(k>=n){
            return accumulate(v.begin(),v.end(),0);
        }
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=v[i];
        }
        int l=k-1,r=n-1,count=k,ans=sum;
        while(count--){
            sum-=v[l];
            sum+=v[r];
            ans=max(ans,sum);
            l--; r--;
        }
        return ans;
    }
};