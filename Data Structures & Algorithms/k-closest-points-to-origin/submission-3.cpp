class Solution {
public:

    struct check {

        double edis(int x, int y) {
            double ans = sqrt(pow(x, 2) + pow(y, 2));
            return ans;
        }

        bool operator()(pair<int,int> p1, pair<int,int> p2) {

            double p1ans = edis(p1.first, p1.second);
            double p2ans = edis(p2.first, p2.second);

            return p1ans < p2ans;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            check
        > heap;

        for(int i = 0; i < points.size(); i++) {

            heap.push({points[i][0], points[i][1]});

            if(heap.size() > k) {
                heap.pop();
            }
        }

        vector<vector<int>> ans;

        while(!heap.empty()) {
            ans.push_back({
                heap.top().first,
                heap.top().second
            });

            heap.pop();
        }

        return ans;
    }
};