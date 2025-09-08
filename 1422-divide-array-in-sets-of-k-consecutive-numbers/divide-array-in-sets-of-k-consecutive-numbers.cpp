class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;

        map<int,int> mp;
        for(auto it: hand){
            mp[it]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it: mp){
            pq.push(it.first);
        }
        while(!pq.empty()){
            int a=pq.top();
            for(int i=a;i<a+groupSize;i++){
                if(mp[i]==0){
                    return false;
                }
                mp[i]--;
                if(mp[i]==0){
                    if(pq.top()!=i){
                        return false;
                    }
                    pq.pop();
                }
            }
        }
        return true;
    }
};