class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& ans, int i) {
        
        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++) {

            swap(nums[i], nums[j]);       // choose

            func(nums, ans, i + 1);       // explore

            swap(nums[i], nums[j]);       // undo
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        func(nums, ans, 0);

        return ans;
    }
};