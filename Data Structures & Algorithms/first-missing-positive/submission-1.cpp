class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         if(nums.size()==1){
            if(nums[0]>1){
                return 1;
            }
         }
         unordered_set<int> myset(nums.begin(),nums.end());
         int max1=*max_element(nums.begin(),nums.end());
         int max=max1;
         int smallest=max;
         if(max<=0){
            return 1;
         }
         while(max>=1){
            if(myset.find(max)==myset.end()){
                smallest=max;
            }
            max--;
         }   
         if(smallest==max1){
            return smallest+1;
         }
         return smallest;
          
        }
};