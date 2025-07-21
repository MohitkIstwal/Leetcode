class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            int a=arr[m]-(m+1);
            if(a<k){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return k+r+1;
    }
};