class Solution {
public:
    void func(vector<int>& nums,int i,int sum, int target,vector<vector<int>>&ans,vector<int>& subset){
        if(sum==target){
            ans.push_back(subset);
            return;
        }
        if(i>=nums.size()||sum>target){
            return;
        }
        for(int idx=i;idx<nums.size();idx++){
        //take
        subset.push_back(nums[idx]);
        sum+=nums[idx];
        func(nums,idx,sum,target,ans,subset);
        sum=sum-nums[idx];
        subset.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>subset;
        func(nums,0,0,target,ans,subset);
        return ans;
    }
};
