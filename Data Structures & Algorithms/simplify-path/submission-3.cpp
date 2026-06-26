class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        stack<string> st;

        while (i < path.size()) {

            string word = "";

            // Skip all '/'
            while (i < path.size() && path[i] == '/') {
                i++;
            }

            // Read one directory name
            while (i < path.size() && path[i] != '/') {
                word += path[i];
                i++;
            }

            if (word == "..") {
                if (!st.empty())
                    st.pop();
            }
            else if (word != "." && !word.empty()) {
                st.push(word);
            }
        }

        stack<string> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        string ans = "";
        while (!temp.empty()) {
            ans += "/" + temp.top();
            temp.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};