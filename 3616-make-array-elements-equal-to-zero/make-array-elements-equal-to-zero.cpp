class Solution {
public:
    int countValidSelections(vector<int>& v) {
        int a=accumulate(v.begin(),v.end(),0);
        int sum=0,ans=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(v[i]==0){
                if(2*sum==a){
                    ans+=2;
                }
                else if(2*sum==a-1 || 2*sum==a+1){
                    ans++;
                }
            }
        }
        return ans;
    }
};