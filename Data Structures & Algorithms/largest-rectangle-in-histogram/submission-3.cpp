class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
 
        int area=0,maxarea=0;
        int mini=INT_MAX;
        for(int i=0;i<h.size();i++){
           int height=h[i];
           int left=i;
           int right=i;
           while(left>=0 && h[left]>=height){
            left--;
           }
           while(right<=h.size()-1 && h[right]>=height){
            right++;
           }
           left+=1;
           right-=1;
           area=height*(right-left+1);
           maxarea=max(area,maxarea);
        }
       
        return maxarea;
    }
};