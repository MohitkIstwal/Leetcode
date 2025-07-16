class Solution {
public:

    bool helper(vector<int> v,int h,int m){
        long long a=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=m){
                a++;
            }
            else{
                a+=(v[i]/m);
                if((v[i]%m)!=0){
                    a++;
                }
            }
        }
        return a<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int a=*max_element(piles.begin(),piles.end());
        int l=1,r=a,ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(helper(piles,h,m)){
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