class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        mymap.insert({0,1});
        int freq=0;
        int prefixSum=0;
        for(auto num :nums){
            prefixSum += num;
            if(mymap.find(prefixSum-k)!=mymap.end()){
                auto val=mymap.find(prefixSum-k);
                freq += val->second;
                
            }
            mymap[prefixSum]++;
        }
        return freq;
    }
};