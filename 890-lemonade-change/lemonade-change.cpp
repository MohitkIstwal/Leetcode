class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        bool bl=true;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five==0){
                    bl=false; break;
                }
                else{
                    five--; ten++;
                }
            }
            else{
                if(ten>0 && five>0){
                    ten--; five--;
                }
                else if(ten==0 && five>=3){
                    five-=3;
                }
                else{
                    bl=false; break;
                }
            }
        }
        return bl;
    }
};