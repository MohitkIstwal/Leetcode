class Solution {
public:
    // okay so idea is basic
    // just create a divisor vector with no of divisors and there sum using sieve type function
    // later just use this precomputed vector to find the ans
    // if no of divisors is equal to 4 then add the sum which is precomputed
    // time complexity will be O(nlogn)
    vector<pair<int,int>> divisors(vector<pair<int,int>> &v){
        for(int i=1;i<=100000;i++){
            for(int j=i;j<=100000;j+=i){
                v[j].first++;
                v[j].second+=i;
            }
        }
        return v;
    }

    int sumFourDivisors(vector<int>& nums) {
        vector<pair<int,int>> v(1e5+7);
        vector<pair<int,int>> ans=divisors(v);
        int result=0;
        for(int i=0;i<nums.size();i++){
            if(ans[nums[i]].first==4){
                result+=ans[nums[i]].second;
            }
        }
        return result;
    }
};