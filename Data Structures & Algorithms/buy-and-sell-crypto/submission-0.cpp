class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum=prices[0]; //buy price minimum
        int profit=0;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            minimum=min(minimum,prices[i]);
            profit=prices[i]-minimum;
            maxprofit=max(maxprofit,profit);
            
        }
        return maxprofit;
    }
};