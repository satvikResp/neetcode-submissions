class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        while(true){
            long long time=0;
            for(int pile:piles){
                time+=pile/i;
                if(pile%i>0){
                    time+=1;
                }
            }
            if(time<=h){
                return i;
            }
            i++;
        }
    }
};
