class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>myset;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        long long temp_target=target;
         for(int i=0;i<nums.size();i++){
            temp_target-=nums[i];
            for(int j=i+1;j<nums.size();j++){
                temp_target-=nums[j];

                int left=j+1;
                int right=nums.size()-1;
               while(left<right){
                      if(nums[left]+nums[right]==temp_target){
                        vector<int>ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[left]);
                        ans.push_back(nums[right]);
                        sort(ans.begin(),ans.end());
                        myset.insert(ans);
                    }
                    if(nums[left]+nums[right]>temp_target){
                        right--;
                    }
                    else{
                        left++;
                    }
                  
                }
                temp_target=target-nums[i];
            }
            temp_target=target;
         }
         vector<vector<int>>s(myset.begin(),myset.end());
         return s;
    }
};