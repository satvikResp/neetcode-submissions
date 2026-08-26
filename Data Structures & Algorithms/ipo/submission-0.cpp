class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        vector<pair<int,int>> projects;

        // {capital, profit}
        for(int i = 0; i < capital.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort according to capital
        sort(projects.begin(), projects.end());

        // Max heap -> highest profit on top
        priority_queue<int> pq;

        int j = 0;

        for(int i = 0; i < k; i++) {

            // Add all currently affordable projects
            while(j < projects.size() && projects[j].first <= w) {
                pq.push(projects[j].second);
                j++;
            }

            // No project is affordable
            if(pq.empty()) {
                break;
            }

            // Take maximum profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};