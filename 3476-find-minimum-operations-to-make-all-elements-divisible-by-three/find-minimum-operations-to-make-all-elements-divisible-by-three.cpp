class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto val: nums){
            if(val%3){
                ans++;
            }
        }
        return ans;
    }
};