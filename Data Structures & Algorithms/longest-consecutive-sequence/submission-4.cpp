class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>myset;
        for(int i=0;i<nums.size();i++){
            myset.insert(nums[i]);
        }
        int cnt=0;
        int maxcnt=0;
        int prevval=0;
        for(auto it:myset){
            if(it==*myset.begin()){
                 cnt++;
                prevval=it;
            }
            else if(it==prevval+1){
                cnt++;
                prevval=it;
            }
            else{
                cnt=1;
                prevval=it;
            }
            if(maxcnt<cnt){
                maxcnt=cnt;
            }
        }
        return maxcnt;
    }
};
