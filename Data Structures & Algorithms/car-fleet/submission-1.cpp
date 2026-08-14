class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> pair;

        for(int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());

        vector<double> stack;

        for(auto &p : pair) {

            double time = (double)(target - p.first) / p.second;

            if(stack.empty()) {
                stack.push_back(time);
            }
            else {
                if(time > stack.back()) {
                    stack.push_back(time);
                }
            }
        }

        return stack.size();
    }
};