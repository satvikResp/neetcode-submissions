class Solution {
public:
    void func(vector<int>&nums,vector<vector<int>>&ans,vector<int>&res,int i){
        
            ans.push_back(res);
            
        
        //take
       for(int idx=i;idx<nums.size();idx++){
        res.push_back(nums[idx]);
        func(nums,ans,res,idx+1);
        res.pop_back();
       
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }
       }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(),nums.end());
        func(nums,ans,res,0);
        return ans;
    }
};
