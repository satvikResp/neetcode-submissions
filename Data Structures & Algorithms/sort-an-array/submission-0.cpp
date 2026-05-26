class Solution {
public:
    int qsort(vector<int>& arr,int low,int high){

        int pivot=arr[low];
        int i=low;
        int j=high;

        while(i<j){
            while(i<high &&arr[i]<=pivot){
                i++;
            }
            while(j>low && arr[j]>=pivot){
                j--;
            }
        
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
    }
    void quicksort(vector<int>&nums,int low,int high){

        if(low<high){
            int partition= qsort(nums,low,high);
            quicksort(nums,low,partition-1);
            quicksort(nums,partition+1,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};