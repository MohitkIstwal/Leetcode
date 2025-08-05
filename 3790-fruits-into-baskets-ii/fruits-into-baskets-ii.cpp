class Solution {
public:
    int numOfUnplacedFruits(vector<int>& freq, vector<int>& cap) {
        map<int,bool> mp; int ans=0;
        for(int i=0;i<cap.size();i++){
            mp[i]=false;
        }
        for(int i=0;i<freq.size();i++){
            int f=0;
            for(int j=0;j<cap.size();j++){
                if(!mp[j] && cap[j]>=freq[i]){
                    mp[j]=true;
                    f=1;
                    break;
                }
            }
            if(f==0){
                ans++;
            }
        }
        return ans;
    }
};