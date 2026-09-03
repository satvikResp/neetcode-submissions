class Solution {
public:
    void func(vector<int>&nums,int i,int xorvalue,int &sum){
       if(i==nums.size()){ 
            sum+=xorvalue;
        return;
        }

       for(int idx=i;idx<nums.size();i++){ 
       func(nums,i+1,xorvalue^nums[i],sum);
        func(nums,i+1,xorvalue,sum);
       return;
       }

    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        int i=0;
        int xorvalue=0;
        func(nums,i,xorvalue,sum);
        return sum;
    }
};