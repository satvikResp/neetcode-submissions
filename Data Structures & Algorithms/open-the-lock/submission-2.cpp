class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if (dead.count("0000"))
            return -1;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            // ek complete BFS level
            while (size--) {

                string current = q.front();
                q.pop();

                if (current == target)
                    return moves;

                for (int i = 0; i < 4; i++) {

                    // +1
                    string next = current;
                    next[i] = (next[i] - '0' + 1) % 10 + '0';

                    if (!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }

                    // -1
                    next = current;
                    next[i] = (next[i] - '0' + 9) % 10 + '0';

                    if (!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};