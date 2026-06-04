class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp=0;
        int n=nums.size();
        k=k%n;
        for(int i=0;i<k;i++){
            temp=nums[n-1];
            for(int j=nums.size()-1;j>0;j--){
                nums[j]=nums[j-1];
            }
            nums[0]=temp;
        }
    }
};