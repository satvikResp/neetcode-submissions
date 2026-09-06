class Solution {
public:
    void func(vector<int>& nums,
              vector<vector<int>>& ans,
              vector<int>& res,
              unordered_set<int>& myset) {

        if(res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }

        unordered_set<int> used;

        for(int i = 0; i < nums.size(); i++) {

            // index already used in current permutation
            if(myset.find(i) != myset.end())
                continue;

            // same value already tried at this level
            if(used.find(nums[i]) != used.end())
                continue;

            used.insert(nums[i]);

            res.push_back(nums[i]);
            myset.insert(i);

            func(nums, ans, res, myset);

            myset.erase(i);
            res.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        unordered_set<int> myset;

        func(nums, ans, res, myset);

        return ans;
    }
};