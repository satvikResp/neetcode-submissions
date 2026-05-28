class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
        for(auto it : mymap){
        heap.push({it.second,it.first});
        if(heap.size()>k){
            heap.pop(); 
         }  
        }
    vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
