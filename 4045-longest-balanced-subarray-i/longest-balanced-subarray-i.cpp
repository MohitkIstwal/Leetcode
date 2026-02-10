class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            map<int,int> odd,even;
            int o=0,e=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0 && even[nums[j]]==0){
                    e++;
                    even[nums[j]]++;
                }
                else if(nums[j]%2!=0 && odd[nums[j]]==0){
                    o++;
                    odd[nums[j]]++;
                }
                if(o==e){
                    ans=max(j-i+1,ans);
                }
            }
        }
        return ans;
    }
};