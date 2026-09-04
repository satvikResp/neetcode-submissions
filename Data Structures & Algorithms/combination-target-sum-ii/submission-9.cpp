class Solution {
public:
 void func(vector<int>& nums,int i,int sum, int target,vector<vector<int>>&ans,vector<int>& subset){

       if(sum==target){
        ans.push_back(subset);
        return;
       }
       if(i>=nums.size() || sum>target) return;
       for(int idx=i;idx<nums.size();idx++){
        subset.push_back(nums[idx]);
        sum+=nums[idx];
        func(nums,idx+1,sum,target,ans,subset);
        sum-=nums[idx];
        subset.pop_back();
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]) idx++;
       }
       return;

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(candidates.begin(),candidates.end());
        func(candidates,0,0,target,ans,subset);
      
    return ans;
    }
};


