class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap.find(nums[i])==mymap.end()){
                mymap[nums[i]]=1;
            }
            else{
                mymap[nums[i]]++;
            }
        }
        int n=nums.size();
        vector<int>ans;
        for(auto it:mymap){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};