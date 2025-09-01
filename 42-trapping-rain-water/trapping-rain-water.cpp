class Solution {
public:
    int trap(vector<int>& height) {
    //just create 2 arrays of next greater and before greater element . after that jsut add in the ans greedily

        int n=height.size();
        vector<int> sufmax(n);
        // premax[0]=height[0];
        // for(int i=1;i<n;i++){
        //     premax[i]=max(premax[i-1],height[i]);
        // }
        sufmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            sufmax[i]=max(sufmax[i+1],height[i]);
        }
        int ans=0,a=0;
        for(int i=0;i<n;i++){
            a=max(a,height[i]);
            if(min(sufmax[i],a)-height[i]>0){
                ans+=min(sufmax[i],a)-height[i];
            }
        }
        return ans;
    }
};