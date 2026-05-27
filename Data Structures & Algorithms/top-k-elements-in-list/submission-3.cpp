class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mymap;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mymap.find(nums[i])==mymap.end()){
                mymap[nums[i]]=1;
            }
            else{
                mymap[nums[i]]++;
                
            }
        }
        int cnt=0;
        int maxele=0;
        int maxfreq=0;
        while(cnt<k){
            maxele=0;
            maxfreq=0;
            for(auto it:mymap){
                if(it.second>maxfreq){
                    maxfreq=it.second;
                    maxele=it.first;
                }
            }
            ans.push_back(maxele);
            mymap[maxele]=0;
            cnt++;
        }
       
        return ans;
    }
};
