class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        // {enqueueTime, {processingTime, index}}
        vector<pair<int, pair<int,int>>> v;

        for(int i = 0; i < tasks.size(); i++) {
            v.push_back({tasks[i][0], {tasks[i][1], i}});
        }

        sort(v.begin(), v.end());

        // {processingTime, index}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while(i < v.size() || !pq.empty()) {

            // Agar heap empty hai, next task ke enqueue time par jao
            if(pq.empty()) {
                time = max(time, (long long)v[i].first);
            }

            // Current time tak available saare tasks heap mein
            while(i < v.size() && v[i].first <= time) {
                pq.push({v[i].second.first, v[i].second.second});
                i++;
            }

            // Sabse chhota processing time
            ans.push_back(pq.top().second);

            time += pq.top().first;
            pq.pop();
        }

        return ans;
    }
};