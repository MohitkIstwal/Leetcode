class Solution {
public:

    int helper(vector<int> v,int k){
        if(k<0){
            return 0;
        }
        int l=0,r=0,count=0,ans=0;
        while(r<v.size()){
            if(v[r]&1){
                count++;
            }
            while(count>k){
                if(v[l]&1){
                    count--;
                }
                l++;
            }
            if(count<=k){
                ans+=(r-l+1);
            }
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};