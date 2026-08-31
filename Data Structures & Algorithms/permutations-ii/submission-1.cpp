class Solution {
public:
    void func(vector<int>&nums,vector<vector<int>>&ans,vector<int>&res,vector<bool>&check){
        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1] && check[i-1] == false)
            continue;
            if(check[i]==false){
                check[i]=true;
                res.push_back(nums[i]);
                func(nums,ans,res,check);
                res.pop_back();
                check[i]=false;
            }
            
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(),nums.end());
        vector<bool>check(nums.size(),false);
        func(nums,ans,res,check);
        return ans;
    }
};