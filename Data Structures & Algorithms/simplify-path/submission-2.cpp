class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;

        path += '/';

        for (char c : path) {
            if (c != '/') {
                cur += c;
                continue;
            }

            if (cur == "..") {
                if (!st.empty()) st.pop_back();
            }
            else if (!cur.empty() && cur != ".") {
                st.push_back(cur);
            }

            cur.clear();
        }

        string ans;

        for (string &dir : st) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};
