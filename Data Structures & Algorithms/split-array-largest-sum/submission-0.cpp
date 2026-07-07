class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=INT_MAX;

        while(l<=r){
            int m=l+(r-l)/2;
            int part=1;
            int runningsum=0;
            for(int num:nums){
             
                if (runningsum + num > m){
                    part++;
                    runningsum=num;
                }
                else    
                runningsum+=num;
            }
            if(part<=k){
                ans=min(ans,m);
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};