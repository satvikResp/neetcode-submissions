class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0;
        int rightmax=0;
        int res=0;
        int  n=height.size();
        vector<int> left(n);
        vector<int> right(n);
         
        left[0] = height[0];
        right[n-1] = height[n-1];

        for(int i=1;i<height.size();i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=height.size()-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }

        for(int i=0;i<height.size();i++){
            

            res+=min(left[i],right[i])-height[i];
        }
        return res;
    }
};
