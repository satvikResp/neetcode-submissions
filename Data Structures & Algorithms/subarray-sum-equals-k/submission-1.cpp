class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int freq = 0;
         
        

        for(int i=0;i<nums.size();i++){
            int prefixSum = 0;
            
            for(int j=i;j<nums.size();j++){
        
                prefixSum += nums[j];
                if(prefixSum == k){
                    freq++;
                }

            }
        }
        return freq;
    }
};