class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(auto& it:freq){
            minheap.push({it.second,it.first});
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        vector<int>res;
        while(res.size()<k){
            res.push_back(minheap.top().second);
            minheap.pop();
            
        }
        return res;
    }
};
