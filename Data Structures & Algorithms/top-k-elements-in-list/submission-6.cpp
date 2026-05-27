class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]++;
        }
        vector<pair<int,int>>ansarr;
        for(auto it :mymap){
            ansarr.push_back({it.second,it.first});
        }
        sort(ansarr.begin(),ansarr.end()); // r revrese ke liye ...descending order me sort krne ke liye
        vector<int>ans;
        for(int i=ansarr.size()-k;i<ansarr.size();i++){
            ans.push_back(ansarr[i].second);
        }
        return ans;
    }
};
