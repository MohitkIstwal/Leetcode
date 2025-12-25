class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        priority_queue<int> pq;
        for(int val: v){
            pq.push(val);
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            int val=pq.top();
            pq.pop();
            val=max(val-i,0);
            ans+=(long long)val;
        }
        return ans;
    }
};