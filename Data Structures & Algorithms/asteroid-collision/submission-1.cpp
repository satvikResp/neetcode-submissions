class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int it : asteroids) {

            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && it < 0) {
                if (st.top() < abs(it)) {
                    st.pop(); 
                    continue;
                }
                else if (st.top() == abs(it)) {
                    st.pop();
                }

                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push(it);
            }
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};