class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(bits[n-1]==1){
            return false;
        }
        bool ans=false;
        for(int i=0;i<n;i++){
            if(i==n){break;}
            if(i==n-1 && bits[i]==0){
                ans=true;
            }
            else{
                if(bits[i]==0){
                    continue;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};