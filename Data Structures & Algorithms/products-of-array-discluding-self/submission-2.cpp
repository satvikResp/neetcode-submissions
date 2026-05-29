class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size());
        int n= nums.size();
        vector<int>lsum(n);
        vector<int>rsum(n);
        lsum[0]=1;
        rsum[n-1]=1;
        
        for(int i=1;i<nums.size();i++){
            lsum[i]=lsum[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rsum[i]=rsum[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            res[i]=lsum[i]*rsum[i];
        }
        return res;
    }
};
