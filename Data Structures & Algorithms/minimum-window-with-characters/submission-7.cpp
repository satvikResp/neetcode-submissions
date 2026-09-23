class Solution {
public:
    string minWindow(string s, string t) {
         int l = 0, r = 0;
    int start = 0;
    int minLen = INT_MAX;

    unordered_map<char,int> need, window;

    for(int i = 0; i < t.size(); i++) {
        need[t[i]]++;
    }

    int valid = 0;

    while(r < s.size()) {

        window[s[r]]++;

        if(need.count(s[r]) &&
           window[s[r]] == need[s[r]]) {
            valid++;
        }

        // Jab tak window valid hai, shrink karte raho
        while(valid == need.size()) {

            if(r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }

            window[s[l]]--;

            if(need.count(s[l]) &&
               window[s[l]] < need[s[l]]) {
                valid--;
            }

            l++;
        }

        r++;
    }

    if(minLen == INT_MAX)
        return "";

    return s.substr(start, minLen);
    }
};
