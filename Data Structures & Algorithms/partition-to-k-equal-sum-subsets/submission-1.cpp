class Solution {
public:
    bool func(vector<int>&nums,vector<int>&subset_sum,int index,int target_sum){
        if(index==nums.size()){
            for(auto it:subset_sum){
                if(it!=target_sum) return false;
            }
            return true;
        }
      
        for(int i=0;i<subset_sum.size();i++){
            if (i > 0 && subset_sum[i] == subset_sum[i - 1])
                continue;
            if(subset_sum[i]+nums[index]<=target_sum){
                subset_sum[i]+=nums[index];
                if(func(nums,subset_sum,index+1,target_sum)) return true;
                subset_sum[i]-=nums[index];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(auto it:nums){
            total+=it;
        }
        if(total%k!=0) return false;
        vector<int>subset_sum(k,0);
        sort(nums.rbegin(),nums.rend());
        
        return func(nums,subset_sum,0,total/k);
    }
};