class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheapforcapital;
        priority_queue<int>maxheapforprofit;

        for(int i=0;i<capital.size();i++){
            minheapforcapital.push({capital[i],profits[i]});
        }

        for(int i=0;i<k;i++){
            while(!minheapforcapital.empty() && minheapforcapital.top().first<=w){
                maxheapforprofit.push(minheapforcapital.top().second);
                minheapforcapital.pop();
            }
            if(maxheapforprofit.empty())
            break;

            w+=maxheapforprofit.top();
            maxheapforprofit.pop();
        }
        return w;
    }
};