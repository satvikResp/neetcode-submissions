class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>leftsum;
        vector<int>rightsum(nums.size());
       
        for(int i=0;i<nums.size();i++){
            if(i==0){
                leftsum.push_back(nums[0]);
            }
            else
            leftsum.push_back(leftsum[i-1]*nums[i]);
        }
        int n=nums.size()-1;
        for(int j=n;j>=0;j--){
            if(j==n){
                 rightsum[j] = nums[j];
            }
            else{
                rightsum[j] = rightsum[j+1] * nums[j];
                }
        }
        
        for(int i=0;i<nums.size();i++){
            if(i==0){
                nums[i]=rightsum[i+1];
            }
            else if(i==n){
                nums[i]=leftsum[i-1];
            }
            else{
                nums[i]=leftsum[i-1]*rightsum[i+1];
            }
        }
        return nums;
    }
};
