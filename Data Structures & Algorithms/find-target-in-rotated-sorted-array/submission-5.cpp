class Solution {
public:
    int findPivot(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            if (nums[l] <= nums[r])
                return l;

            int mid = l + (r - l) / 2;

            if (nums[mid] >= nums[0])
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        // Array not rotated
        if (pivot == 0)
            return binarySearch(nums, 0, n - 1, target);

        // Target lies in left sorted half
        if (target >= nums[0] && target <= nums[pivot - 1])
            return binarySearch(nums, 0, pivot - 1, target);

        // Otherwise search right half
        return binarySearch(nums, pivot, n - 1, target);
    }
};