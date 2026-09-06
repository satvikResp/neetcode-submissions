class Solution {
public:
    bool func(vector<int>&ms,vector<int>&sum,int idx,int total){
        if(idx>=ms.size() && sum[0]==total && sum[1]==total && sum[2]==total && sum[3]==total ){
            return true;
            return false;
        }
        if(sum[0]>total ||sum[1]>total || sum[2]>total ||sum[3]>total) return false;
        for(int i=0;i<4;i++){//choose side

        //agr pichla hi elemnt hai to phirse check mt kro
        if(i > 0 && sum[i] == sum[i-1])
        continue;
        //add to the sides sum 
        //only if sum will be less than side sum required    
        if(sum[i] + ms[idx] > total)
        continue;

            sum[i]+=ms[idx];
            if(func(ms,sum,idx+1,total)) return true;
            //remove form the side sum
            sum[i]-=ms[idx];
            //try other side
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        vector<int>sum(4,0);
        int total=0;
        for(auto it:matchsticks){
            total+=it;
        }
        if(total % 4!=0) return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        int side_sum=total/4;
        return func(matchsticks,sum,0,side_sum);
    }
};