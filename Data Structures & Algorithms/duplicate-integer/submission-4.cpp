class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       set<int>myset;
       for(int num:nums){
        if(myset.count(num)){
            return true;
        }
        myset.insert(num);
       }
        return false;
    }
};
