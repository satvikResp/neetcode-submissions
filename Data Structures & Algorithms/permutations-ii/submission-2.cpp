class Solution {
public:
    void func(vector<int>& nums,
              vector<vector<int>>& ans,
              vector<int>& res,
              vector<bool>& used) {

        if(res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(used[i])
                continue;

            // duplicate choice at same level
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;

            res.push_back(nums[i]);
            used[i] = true;

            func(nums, ans, res, used);

            used[i] = false;
            res.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> used(nums.size(), false);

        func(nums, ans, res, used);

        return ans;
    }
};