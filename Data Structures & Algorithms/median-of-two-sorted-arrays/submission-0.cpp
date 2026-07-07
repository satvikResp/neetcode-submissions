class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
int n = nums1.size() - 1;
int m = nums2.size() - 1;
vector<int> arr(n + m + 2);
int k = 0;

int i = 0, j = 0;

while (i <= n && j <= m) {
    if (nums1[i] <= nums2[j]) {
        arr[k] = nums1[i];
        i++;
    } else {
        arr[k] = nums2[j];
        j++;
    }
    k++;
}

while (i <= n) {
    arr[k++] = nums1[i++];
}

while (j <= m) {
    arr[k++] = nums2[j++];
}

double ans = 0;

if (k % 2 == 0) {
    int idx = k / 2;
    ans = (arr[idx - 1] + arr[idx]) / 2.0;
} else {
    int idx = k / 2;
    ans = arr[idx];
}

return ans;
    }
};
