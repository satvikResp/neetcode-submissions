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
        func(nums,i+1,sum,target,ans,subset);
        
        sum=sum-nums[i];
        subset.pop_back();
        
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        //not take
        func(nums,i+1,sum,target,ans,subset);
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

