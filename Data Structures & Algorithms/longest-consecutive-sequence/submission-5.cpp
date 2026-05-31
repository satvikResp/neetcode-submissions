class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>myset;
        for(int i : nums){
            myset.insert(i);
        }
        int seqcnt = 0;

        int maxseqcnt=0;
        
        int crnt=0;
        
        for(auto &it :nums){
            crnt = it;
            seqcnt=0;
             if(myset.find(crnt-1)==myset.end()){   //prev ele nahi tha set me
                while(myset.find(crnt)!=myset.end()){   //ye wala ele hai set me
                    seqcnt++;
                    crnt++;
                }
             }
             if(seqcnt>maxseqcnt){
                maxseqcnt=seqcnt;
             }
          
        }
        return maxseqcnt;
    }
};
