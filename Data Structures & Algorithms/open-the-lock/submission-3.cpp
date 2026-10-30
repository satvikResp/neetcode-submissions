class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if (dead.count("0000")) return -1;

        queue<string> q;

        q.push("0000");
        visited.insert("0000");

        int steps = 0;

        while (!q.empty()) {

            int n = q.size();

            while (n--) {

                string crnt = q.front();
                q.pop();

                if (crnt == target) {
                    return steps;
                }

                for (int i = 0; i < 4; i++) {

                    string up = crnt;
                    string down = crnt;

                    up[i] = (up[i] - '0' + 1) % 10 + '0';
                    down[i] = (down[i] - '0' + 9) % 10 + '0';

                    if (!dead.count(up) && !visited.count(up)) {
                        visited.insert(up);
                        q.push(up);
                    }

                    if (!dead.count(down) && !visited.count(down)) {
                        visited.insert(down);
                        q.push(down);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};