class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap.find(nums[i])==mymap.end()){
                mymap.insert({nums[i],1});
            }
            else{
                return true;
            }
        }
        return false;

    }
};
