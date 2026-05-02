class Solution {
public:

    // okay so first we will be checking the whitespace in front and then the sign og the number

    //now in helper we will be writing the recursive code which will be adding the number bit by bit

    void helper(string &s,long long &num,int sign,int i){
        if(i==s.size()){
            return;
        }
        if(s[i]>'9' || s[i]<'0'){
            return;
        }
        int n=s[i]-'0';
        num=abs(num);
        num*=10;
        num+=n;
        num*=sign;
        if(num>=INT_MAX){
            num=INT_MAX;
            return;
        }
        if(num<=INT_MIN){
            num=INT_MIN;
            return;
        }
        helper(s,num,sign,i+1);
    }

    int myAtoi(string s) {
        if(s.size()==0){
            return 0;
        }
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        long long num=0;
        helper(s,num,sign,i);
        return num;
    }
};