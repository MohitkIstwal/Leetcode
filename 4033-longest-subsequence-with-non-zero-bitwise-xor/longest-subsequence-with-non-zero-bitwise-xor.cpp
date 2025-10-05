class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> v(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)){
                    v[i]++;
                }
            }
        }
        bool bl=false;
        for(int i=0;i<32;i++){
            if(v[i]&1){
                return nums.size();
            }
            else if(v[i]>0){
                bl=true;
            }
        }
        if(bl==false){
            return 0;
        }
        int a=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                a++;
            }
        }
        if(a==1){
            return 0;
        }
        return nums.size()-1;
    }
};