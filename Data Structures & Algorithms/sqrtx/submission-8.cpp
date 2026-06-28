class Solution {
public:
    int mySqrt(int x) {
        if(x<=1){
            return x;
        }
        int ans;
        int l=0,r=x;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid<=x/mid){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};