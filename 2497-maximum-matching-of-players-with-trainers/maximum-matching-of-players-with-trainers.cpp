class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end()); sort(trainers.begin(),trainers.end());
        int ans=0;
        for(int i=0,j=0;i<players.size() && j<trainers.size();i++){
            while(j<trainers.size() && trainers[j]<players[i]){
                j++;
            }
            if(j<trainers.size() && trainers[j]>=players[i]){
                ans++; j++;
            }
            if(j==trainers.size()){
                break;
            }
        }
        return ans;
    }
};