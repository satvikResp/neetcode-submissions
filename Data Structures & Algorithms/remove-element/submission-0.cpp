class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        int n=nums.size();
        while(i!=n){
            if(nums[i]==val){
                j=i;
                while(j!=n){
                    if(nums[j]!=val){
                        swap(nums[i],nums[j]);
                        break;
                    }
                    else{
                        j++;
                    }
                }
            }
            i++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                cnt++;
            }
        }
        return cnt;
    }
};