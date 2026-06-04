class Solution {
public:
    int maxArea(vector<int>& nums) {
        int currarea=0;
        int maxarea=0;

        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            currarea=(j-i) * min(nums[i],nums[j]);

            if(maxarea<currarea){
                maxarea=currarea;
            }
            if(nums[i]<=nums[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxarea;
    }
};
