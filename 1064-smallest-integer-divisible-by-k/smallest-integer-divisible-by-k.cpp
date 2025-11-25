class Solution {
public:

    /*
        so any even number can't be taken 
        aside from that we have to see
         for 3 - 111 if the number
         so other one is 37 who is also 111
         no ending with 5 also doesnt have
         lets take example of no 21 - 111

         ok so here is what i did
         first even and divisible by 5 will give -1
         all others will give ans
         so first check if k contains only 1 in it then it is the size
         then create no greater than k and find remainder and keep adding it and then check till it becomes zero and add no of operations to do so 
    */

    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0){
            return -1;
        }
        int k1=k;
        int cnt=1,cnt2=0;
        while(k1){
            int c=k1%10;
            if(c==1){
                cnt2++;
            }
            k1/=10;
            cnt++;
        }
        if(cnt2==cnt-1){
            return cnt2;
        }
        string s="";
        for(int i=0;i<cnt;i++){
            s.push_back('1');
        }
        int n=stoi(s);
        int a=n%k;
        cout<<a<<" ";
        if(!a) return s.size();
        int ad=0;
        while(a!=0){
            string s1=to_string(a);
            s1.push_back('1');
            n=stoi(s1);
            a=n%k;
            ad++;
        }
        return s.size()+ad;
    }
};