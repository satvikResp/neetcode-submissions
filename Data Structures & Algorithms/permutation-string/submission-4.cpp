class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int k = s1.size();

        if (k > s2.size())
            return false;

        unordered_map<char, int> need, window;

        // Frequency of s1
        for (char c : s1)
            need[c]++;

        int l = 0;

        for (int r = 0; r < s2.size(); r++) {

            char c = s2[r];
            window[c]++;

            // Shrink window if current character's frequency exceeds need
            while (window[c] > need[c]) {
                char leftChar = s2[l];
                window[leftChar]--;
                l++;
            }

            // If window size equals s1 length, permutation found
            if (r - l + 1 == k)
                return true;
        }

        return false;
    }
};