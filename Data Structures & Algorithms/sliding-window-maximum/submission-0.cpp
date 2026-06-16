class Solution {
public:
    void getmax(int i ,int j ,vector<int>&nums,vector<int>&ans){
        int maxele=-1;
        for(int k=i;k<=j;k++){
            maxele=max(maxele,nums[k]);
        }
        ans.push_back(maxele);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        int maxele=-1;
        vector<int>ans;
        while(j<nums.size()){
            maxele=max(maxele,nums[j]);
            while(j-i+1>=k){
                getmax(i,j,nums,ans);
                i++;
            }
            
            j++;
        }
        return ans;
    }
};
