class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++){
            int cnt=abs(nums[i]);
            int ind=i;
            if(nums[i]>=0){
                while(cnt--){
                    ind++;
                    if(ind==n){
                        ind=0;
                    }
                }
            }
            else{
                while(cnt--){
                    ind--;
                    if(ind==-1){
                        ind=n-1;
                    }
                }
            }
            result[i]=nums[ind];
        }
        return result;
    }
};