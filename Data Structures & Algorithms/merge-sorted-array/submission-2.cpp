class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int fullsize=nums1.size()-1;
        int i=m-1,j=n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[fullsize]=nums1[i];
                i--;
                fullsize--;
            }
            else{
                 nums1[fullsize]=nums2[j];
                 j--;
                 fullsize--;
            }
        }
        while(j>=0){
            nums1[fullsize]=nums2[j];
            j--;
            fullsize--;
        }
        
    }
};