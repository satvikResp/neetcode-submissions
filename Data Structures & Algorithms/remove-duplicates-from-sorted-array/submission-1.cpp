class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int>myset(nums.begin(),nums.end());
        // sort(myset.begin(),myset.end());
        vector<int>ans(myset.begin(),myset.end());
        sort(ans.begin(),ans.end());
        int count=myset.size();
        int i=0;
        for(auto num: ans){
            nums[i]=num;
            i++;
        }
        return count;
    }
};