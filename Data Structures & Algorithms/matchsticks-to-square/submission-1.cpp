class Solution {
public:
    bool func(vector<int>& ms, int i, vector<int>& sides, int target) {

        // Saare sticks use ho gaye
        if (i == ms.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        // Current stick ko 4 sides mein try karo
        for (int j = 0; j < 4; j++) {

            // Is side mein stick fit ho sakti hai?
            if (sides[j] + ms[i] <= target) {

                // Choose
                sides[j] += ms[i];

                // Explore
                if (func(ms, i + 1, sides, target))
                    return true;

                // Undo
                sides[j] -= ms[i];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int total = 0;
        for (int x : matchsticks)
            total += x;

        // 4 equal sides possible hi nahi
        if (total % 4 != 0)
            return false;

        int target = total / 4;

        // Agar koi stick target se badi hai
        for (int x : matchsticks) {
            if (x > target)
                return false;
        }

        vector<int> sides(4, 0);

        return func(matchsticks, 0, sides, target);
    }
};