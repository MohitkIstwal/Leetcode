class Solution {
public:

    void sieve(vector<bool> &v){
        v[0]=false;
        v[1]=false;
        for(int i=2;i<1e5+7;i++){
            for(int j=2*i;j<1e5+7;j+=i){
                v[j]=false;
            }
        }
    }

    int minOperations(vector<int>& nums) {
        vector<bool> v(1e5+7,true);
        sieve(v); 
        vector<int> primes;
        for(int i=0;i<1e5+7;i++){
            if(v[i]){
                primes.push_back(i);
                //cout<<i<<" ";
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            //cout<<v[nums[i]]<<" ";
            if(i%2==0){
                if(!v[nums[i]]){
                    auto it=upper_bound(primes.begin(),primes.end(),nums[i]);
                    ans+=*it-nums[i];
                }
            }
            else{
                if(v[nums[i]]){
                    if(nums[i]==2){
                        ans+=2;
                    }
                    else{
                        ans++;
                    }
                }
            }
            cout<<ans<<" ";
        }
        return ans;
    }
};