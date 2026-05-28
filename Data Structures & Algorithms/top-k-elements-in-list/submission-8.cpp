class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            mymap[nums[i]]++;
        }
        int n=nums.size();
        vector<vector<int>>bucket(n+1);

        for(auto it:mymap){
            bucket[it.second].push_back(it.first);
        }
        vector<int>res;
        for(int i =n;i>0;i--){
             for(int num : bucket[i]){
                res.push_back(num);
             }
            if(res.size()==k){
                return res;
            }
        }
        return res;
    }
};
