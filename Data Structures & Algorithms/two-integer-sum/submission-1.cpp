class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ansarr;
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            mymap.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){

            int need=target-nums[i];
            auto idx=mymap.find(need);
            
            if(idx !=mymap.end() && idx->second!=i ){

                    if(i<idx->second){
                    ansarr.push_back(i);
                    ansarr.push_back(idx->second);
                    }
                    else{
                    ansarr.push_back(idx->second);
                    ansarr.push_back(i);
                    }
                    return ansarr;
            }
            
        }
        return ansarr;
    }
};
