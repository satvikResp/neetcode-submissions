class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int calSum=0;
        while(j>0 && i<nums.size()-1){
            
            calSum=nums[i]+nums[j];
            if(calSum==target){
                break;
            }
            if( calSum > target){
                j--;
            }
            else{
                i++;
            }
        }
        vector<int>ans;
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
    }
};
