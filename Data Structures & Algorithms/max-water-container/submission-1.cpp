class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int wall=INT_MAX;
        int amt=0;
        int maxi=-1;
        while(i<j){

            wall=min(heights[i],heights[j]);
            amt=wall*(j-i);
            maxi=max(maxi,amt);
            if(heights[i]<heights[j]){
                i++;
            }
            else {
                j--;
            }
            
        }
        return maxi;
    }
};
