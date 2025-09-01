class Solution {
public:
    int trap(vector<int>& height) {
        //the optimal solution is more of a 2 pointer approach

        int lmax,rmax,t,l; lmax=rmax=t=l=0;
        int r=height.size()-1;
        while(l!=r){
            if(height[l]<=height[r]){
                if(lmax>height[l]){
                    t+=lmax-height[l];
                }
                else{
                    lmax=height[l];
                }
                l++;
            }
            else{
                if(rmax>height[r]){
                    t+=rmax-height[r];
                }
                else{
                    rmax=height[r];
                }
                r--;
            }
        }
        return t;
    }
};