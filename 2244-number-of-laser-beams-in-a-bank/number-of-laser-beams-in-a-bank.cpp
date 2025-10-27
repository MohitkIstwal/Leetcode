class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for(auto val: bank){
            int a=0;
            for(auto it: val){
                if(it=='1'){
                    a++;
                }
            }
            if(a){
                v.push_back(a);
            }
        }
        if(v.size()<2){
            return 0;
        }
        int ans=0;
        for(int i=0;i<v.size()-1;i++){
            ans+=v[i]*v[i+1];
        }
        return ans;
    }
};