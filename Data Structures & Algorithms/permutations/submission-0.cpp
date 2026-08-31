class Solution {
public:
    void func(vector<int>& nums,vector<vector<int>>& ans,vector<int>& res,unordered_set<int>&myset){
        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(myset.find(nums[i])==myset.end()){
                res.push_back(nums[i]);
                myset.insert(nums[i]);
                func(nums,ans,res,myset);
                myset.erase(nums[i]);
                res.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> res; 
        unordered_set<int> myset;
        func(nums, ans, res,myset); 

        return ans; 
    }
};
