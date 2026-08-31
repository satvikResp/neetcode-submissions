class Solution {
public:
    void func(vector<int>&nums,vector<vector<int>>&ans,vector<int>&res,int i){
        if(i==nums.size()){
            ans.push_back(res);
            return;
        }
        //take
       
        res.push_back(nums[i]);
        func(nums,ans,res,i+1);
        res.pop_back();
        //phle lele ...sirf phli occourence hi leni hai .....phir check kr ki agla out of bounds to nhi jara and main chij ki vo pichle wala hi to nhi ...agr hai to agli value dekh
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        func(nums,ans,res,i+1);
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
