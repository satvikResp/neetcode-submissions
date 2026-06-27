class Solution {
public:
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> strSt;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            // 1. number build karo
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // 2. '[' => push state
            else if (ch == '[') {
                numSt.push(num);
                strSt.push(curr);

                num = 0;
                curr = "";
            }

            // 3. ']' => pop and build
            else if (ch == ']') {
                int k = numSt.top();
                numSt.pop();

                string prev = strSt.top();
                strSt.pop();

                string temp = "";
                for (int i = 0; i < k; i++) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            // 4. normal character
            else {
                curr += ch;
            }
        }

        return curr;
    }
};