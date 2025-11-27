class Solution {
public:


    //  (i - j) % k == 0
    // → i % k == j % k


    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // this stores the min ps[(i+1)%k] so after difference ans can be max
        vector<long long> ps(n+1,LONG_LONG_MAX);
        ps[0]=0;
        long long ans=LONG_LONG_MIN;
        //to sum till that index
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int r=(i+1)%k;
            if(ps[r]!=LONG_LONG_MAX){
                ans=max(ans,sum-ps[r]);
            }
            ps[r]=min(sum,ps[r]);
        }
        return ans;
    }
};