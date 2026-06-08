class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>bucket(n+1);
        unordered_map<int,int>mymap;
        for(int i=0;i<n;i++){
            mymap[nums[i]]++;
        }
        for(auto it :mymap){
            bucket[it.second].push_back(it.first);
        }
        vector<int>res;
        for(int i=n;i>=0;i--){
            for(auto it:bucket[i])
            res.push_back(it);
            if(res.size()==k){
                return res;
            }
        }
        return res;
    }
};
