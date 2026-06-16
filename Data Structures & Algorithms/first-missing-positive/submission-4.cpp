class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        int index=0;
        while(i<nums.size()){
        if(nums[i]<=0 || nums[i]>nums.size()){
            i++;
            continue;
        }
        index=nums[i]-1;
        if(nums[i]==nums[index]){
            i++;
            continue;
        }
        swap(nums[i],nums[index]);
        
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
                }
        }
        return nums.size()+1;
    }
};