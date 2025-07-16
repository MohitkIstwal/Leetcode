class Solution {
public:

    bool helper(vector<int> v,int d,int m){
        int cnt=0,sum=0;
        int a=*max_element(v.begin(),v.end());
        if(m<a){
            return false;
        }
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(sum>m){
                cnt++;
                sum=v[i];
            }
        }
        if(sum){
            cnt++;
        }
        return cnt<=d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=1e9,ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(helper(weights,days,m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};