class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        int count[26]={0};
        for(int i=0;i<v.size();i++){
            count[v[i]-'A']++;
        }

        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                pq.push(count[i]);
            }
        }
        int ans=0;
        while(!pq.empty()){
            int a=n+1;
            vector<int> store;
            int c=0;
            while(a-- && !pq.empty()){
                if(pq.top()>1){
                    int b=pq.top();
                    store.push_back(b-1);
                }
                pq.pop();
                c++;
            }

            for(int val: store){
                pq.push(val);
            }

            if(pq.empty()){
                ans+=c;
            }
            else{
                ans+=(n+1);
            }
        }
        return ans;
    }
};