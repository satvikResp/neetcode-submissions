class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>myset;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(i-l >k){
                myset.erase(nums[l]);
                l++;
            }
            if(myset.contains(nums[i])){
                return true;
            }
            else{
                myset.insert(nums[i]);
            }
        }    
       return false;
    }
};