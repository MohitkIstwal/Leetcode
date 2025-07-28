class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int t=1<<n,m=-1,a=0,ans=0;
        cout<<t;
        for(int i=0;i<t;i++){
            a=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    a|=nums[j];
                }
            }
            if(m<a){
                m=a;
                ans=1;
            }
            else if(a==m){
                ans++;
            }
        }
        return ans;
    }
};