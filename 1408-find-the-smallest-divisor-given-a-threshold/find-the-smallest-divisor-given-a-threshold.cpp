class Solution {
public:

    bool helper(vector<int> v,int t, int m){
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=(v[i]/m);
            if(v[i]%m){
                sum++;
            }
        }
        return sum<=t;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int a=*max_element(nums.begin(),nums.end());
        int l=1,r=a,ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(helper(nums,threshold,m)){
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