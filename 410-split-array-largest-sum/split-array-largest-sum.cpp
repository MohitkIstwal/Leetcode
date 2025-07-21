class Solution {
public:

    bool helper(vector<int> v,int k,int m){
        int sum=0,a=1;
        for(int i=0;i<v.size();i++){
            if(sum+v[i]>m){
                sum=v[i];
                a++;
            }
            else{
                sum+=v[i];
            }
        }
        if(sum>m){
            a++;
        }
        return a<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=0,r=accumulate(nums.begin(),nums.end(),0),ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(helper(nums,k,m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return max(ans,*max_element(nums.begin(),nums.end()));
    }
};