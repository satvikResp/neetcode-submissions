class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char,int> freq;
            int maxfreqinmap = 0;

            for (int j = i; j < s.size(); j++) {
                freq[s[j]]++;

                maxfreqinmap = max(maxfreqinmap, freq[s[j]]);

                int len = j - i + 1;

                if (len - maxfreqinmap <= k) {
                    res = max(res, len);
                }
            }
        }

        return res;
    }
};