class Solution {
public:
    void func(vector<int>& nums,vector<vector<int>>&ans,vector<int>&subset,int i){
        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }
        for(int idx=i;idx<nums.size();idx++){
        subset.push_back(nums[i]);
        func(nums,ans,subset,i+1);
        subset.pop_back();
        func(nums,ans,subset,i+1);
        return;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        int i=0;
        func(nums,ans,subset,i);
        return ans;
    }
};
