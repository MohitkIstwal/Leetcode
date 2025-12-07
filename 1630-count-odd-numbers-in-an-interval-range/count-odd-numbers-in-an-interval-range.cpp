class Solution {
public:
    int countOdds(int low, int high) {
        int bet=(high-low)/2;
        if(low&1){bet++;}
        else if((high-low)&1){
            bet++;
        }
        return bet;
    }
};