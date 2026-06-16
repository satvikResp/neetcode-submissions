class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>myset;
        for(int i=0;i<nums.size();i++){
            myset.insert(nums[i]);
        }
        int cnt=0;
        int maxcnt=0;
        int num=0;
        for(int i=0;i<nums.size();i++){
            if(myset.contains(nums[i]-1)!=1){
                num=nums[i];
                while(myset.contains(num)){
                    cnt++;
                    num++;
                }
                maxcnt=max(maxcnt,cnt);
                cnt=0;
            }
        }
        return maxcnt;
    }
};
