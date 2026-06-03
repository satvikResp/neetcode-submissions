class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        int j=0; //unique lement assumed 
        for(int i=1;i<nums.size();i++){
            if(nums[j]==nums[i]){
                continue;
            }
            else{
                j++;
                nums[j]=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};