class Solution {
public:

    bool helper(vector<int> v,int m ,int k, int mid){
        int a=0,cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=mid){
                a++;
            }
            else{
                a=0;
            }
            if(a==k){
                cnt++; a=0;
            }
        }
        return cnt>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long a=1LL*m*k;
        int n=bloomDay.size();
        if(a>(long long)n){
            return -1;
        }
        a=*max_element(bloomDay.begin(),bloomDay.end());
        int l=1,r=a,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(helper(bloomDay,m,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};