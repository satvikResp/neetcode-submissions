class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int leftmax=height[i];
        int rightmax=height[j];
        int watertrapped=0;
        while(i<j){
            if(leftmax<rightmax){
                i++;
                leftmax=max(leftmax,height[i]);
                watertrapped+=leftmax-height[i];
            }
            else{
                j--;
                rightmax=max(rightmax,height[j]);
                watertrapped+=rightmax-height[j];
            }
        }
        return watertrapped;
    }
};
