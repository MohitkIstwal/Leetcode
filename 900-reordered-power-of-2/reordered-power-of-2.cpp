class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v;
        while(n!=0){
            v.push_back(n%10);
            n/=10;
        }
        sort(v.begin(),v.end());
        int a=1;
        for(int i=0;i<31;i++){
            vector<int> temp;
            int b=a;
            while(b!=0){
                temp.push_back(b%10);
                b/=10;
            }
            sort(temp.begin(),temp.end());
            if(v==temp){
                return true;
            }
            a=a<<1;
        }
        return false;
    }
};