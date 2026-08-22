class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
                // enqueue process index
        vector<tuple<int,int,int>>sorted;
        for(int i=0;i<tasks.size();i++){
            sorted.push_back( {tasks[i][0],tasks[i][1],i });
        }
        sort(sorted.begin(),sorted.end());
        int i=0;
        long long time=0;
                       //process index
        priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;
        vector<int>ans; 
        while(i<sorted.size() || !pq.empty()){
             
            //agar abhi koi bhi availiable nhi hai to directly vhi pahuncho
            if(pq.empty()) {
            time = max(time, (long long)get<0>(sorted[i]));
            }

            while(i < sorted.size() && time >= get<0>(sorted[i])) {
                 pq.push({get<1>(sorted[i]), get<2>(sorted[i])});
                 i++;
            }
           
            //process kro task sirf ek hi kyunki kya pta ek ho time bdhe aur naye task aye to ab jo kam processing time ya index wala hoga vo ayega na to sirf ek hi kro
           if(!pq.empty()){
               time += pq.top().first;
               ans.push_back(pq.top().second);
                pq.pop();
            }
           
        }
        return ans;
    }
};