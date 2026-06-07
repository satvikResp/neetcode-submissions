class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap.find(nums[i])!=mymap.end()){
                auto it=mymap.find(nums[i]);
                if(abs(i-it->second)<=k){
                    return true;
                }
            }
            mymap[nums[i]]=i;
        }
        return false;
       
    }
};