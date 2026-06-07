class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left=0;
        int i=0;
        for(i=0;i<nums.size();i++){
            while(abs(i-left)>k){
                left++;
            }
            int temp=left;
            while(temp<i){
            if(nums[i] == nums[temp]){
                return true;
            }
            temp++;
            }
        }
        return false;
    }
};