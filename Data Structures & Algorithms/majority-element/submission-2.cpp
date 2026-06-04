class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int res=0;

        int i=0;
        while(i<nums.size()){
            if(cnt==0){
                res=nums[i];
                cnt=1;
                
            }
            else if(res==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
            i++;
        }
        return res;
    }
};