class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--){
            int a=nums[i];
            while(a){
                ans.push_back(a%10);
                a/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};