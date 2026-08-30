class Solution {
public:
    void func(vector<int>&nums,int i,int &xorvalue,int &sum){
       if(i==nums.size()){ 
            sum+=xorvalue;
        return;
        }

       //take 
       xorvalue=xorvalue^nums[i];
       func(nums,i+1,xorvalue,sum);
       xorvalue=xorvalue^nums[i];
       
       //not take
    
       func(nums,i+1,xorvalue,sum);
       return;


    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        int i=0;
        int xorvalue=0;
        func(nums,i,xorvalue,sum);
        return sum;
    }
};