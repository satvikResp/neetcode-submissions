class Solution {
public:
struct check {
    int edis(int x,int y){
        return x * x + y * y;
    }
    bool operator()(pair<int,int> p1, pair<int,int> p2) {
        int p1ans = edis(p1.first, p1.second);
        int p2ans = edis(p2.first, p2.second);

        return p1ans < p2ans;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,check>heap;
        for(int i=0;i<points.size();i++){
           heap.push({points[i][0],points[i][1]});
            if(heap.size()>k){
                heap.pop();
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            vector<int>res;
            ans.push_back({heap.top().first,heap.top().second});
            heap.pop();
        }
        return ans;
    }
};
