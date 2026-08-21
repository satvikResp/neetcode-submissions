class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
        int cnt=0;
        int i=0;
        int remaining=capacity;
        auto cmp=[](vector<int>a,vector<int>b){
            return a[1]<b[1];
        };
        sort(trips.begin(),trips.end(),cmp);
        while(i<trips.size()){
            
            //drop
            while(!heap.empty()){
                if(heap.top().first<=cnt){
                    remaining+=heap.top().second;
                    heap.pop();
                }
                else break;
            }

            //pickup
            while(i < trips.size() && trips[i][1] == cnt){
                if(trips[i][0]>remaining) return false;
                
                 remaining=remaining-trips[i][0];
                        //drop point , total passangers
                heap.push({trips[i][2],trips[i][0]}); 
                i++;
            }
            if (i < trips.size())
                cnt = trips[i][1];
             
        }
        return true;
    }
};