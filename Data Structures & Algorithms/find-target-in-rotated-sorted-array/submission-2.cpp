class Solution {
public:
    int pivot(vector<int>& nums){
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[l]<nums[r]){
                return l;
            }
            if(nums[mid]>=nums[l]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int pvtindex=pivot(nums);
        int l =0,r=nums.size()-1;
        if(target>=nums[0] && target>nums[r]){
            l=0;
            r=pvtindex-1;
        }
        else{
            l=pvtindex;
            r=nums.size()-1;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};
