class Solution {
public:
  
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        priority_queue<pair<int,int>>maxheap;
        int maxele=-1;
        vector<int>ans;
        while(j<nums.size()){
            maxheap.push({nums[j],j});
            
            if(j-i+1==k){
                
                while(!maxheap.empty()&& i>maxheap.top().second){
                    maxheap.pop();
                }
                ans.push_back(maxheap.top().first);
                i++;
            }
            
            j++;
        }
        return ans;
    }
};
