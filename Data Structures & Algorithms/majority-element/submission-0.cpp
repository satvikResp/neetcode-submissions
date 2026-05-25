class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<unsigned int,unsigned int>mymap;
        for(int i=0;i<nums.size();i++){
            if(mymap.find(nums[i])!=mymap.end()){
                mymap[nums[i]]++;
            }
            else
            mymap[nums[i]]=1;
        }
        int maxi=0;
        int maxele=0;
        for(auto it: mymap){
           
            if(maxi<it.second){
                maxi=it.second;
                maxele=it.first;
            }
        }
        return maxele;
    }
};