class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();
        deque<int> dq; 
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            while(!dq.empty() && v[i] >= v[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i >= k-1){
                ans.push_back(v[dq.front()]);
            }
        }

        return ans;
    }
};
