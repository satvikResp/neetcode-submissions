class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         
         int max1=*max_element(nums.begin(),nums.end());
         int max=max1;
         int smallest=max;
         if(max<=0){
            return 1;
         }
         while(max>=1){
            if(find(nums.begin(),nums.end(),max)==nums.end()){
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