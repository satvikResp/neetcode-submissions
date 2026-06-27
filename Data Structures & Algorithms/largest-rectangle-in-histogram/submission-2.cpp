class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
 
        int area=0,maxarea=0;
        int mini=INT_MAX;
        for(int i=0;i<h.size();i++){
            mini=INT_MAX;
            for(int j=i;j<h.size();j++){
                mini=min(mini,h[j]);
                area=mini*(j-i+1);
                maxarea=max(area,maxarea);
            }

        }
       
        return maxarea;
    }
};