class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& ans,
              vector<int>& res, vector<bool>& myset) {

        if(res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(myset[i]) {
                continue;
            }

            // choose
            res.push_back(nums[i]);
            myset[i] = true;

            // explore
            func(nums, ans, res, myset);

            // undo
            myset[i] = false;
            res.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> myset(nums.size(), false);

        func(nums, ans, res, myset);

        return ans;
    }
};