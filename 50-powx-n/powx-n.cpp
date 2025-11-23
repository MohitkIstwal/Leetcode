class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            x=(1/x);
            n=-n;
        }

        double h=myPow(x,n/2);

        if(n&1){
            return h*h*x;
        }
        else{
            return h*h;
        }
    }
};