class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        float sum=nums[n-1];
        float div=1;
        int ans=0;
        for(int i=n-2;i>=0;i--){
            float a=(float)nums[i];
            float b=sum/div;
            if(a>b){
                ans++;
            }
            sum+=(float)nums[i]; div++;
        }
        return ans;
    }
};