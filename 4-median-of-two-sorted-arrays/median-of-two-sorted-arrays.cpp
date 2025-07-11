class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        if(v.size()&1){
            double d=(double)v[v.size()/2];
            return d;
        }
        int a=v.size()/2;
        int b=a--;
        double x=(double)v[a];
        double y=(double)v[b];
        double d=(double)(((x+y))/2);
      //  cout<<v[a]<<" "<<v[b]<<" ";
        return d;
    }
};