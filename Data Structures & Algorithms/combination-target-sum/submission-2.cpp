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
        //take
        subset.push_back(nums[i]);
        sum+=nums[i];
        func(nums,i,sum,target,ans,subset);
        sum=sum-nums[i];
        subset.pop_back();
        //not take
        func(nums,i+1,sum,target,ans,subset);
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>subset;
        func(nums,0,0,target,ans,subset);
        return ans;
    }
};
