class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        unordered_set<int>myset;
        while(j<nums.size()){
            
            if(abs(i-j)>k){
                myset.erase(nums[i]);
                i++;
            }
            if(myset.contains(nums[j])) return true;
            myset.insert(nums[j]);
            j++;
        }
        return false;
    }
};