Median of Two Sorted Arrays :

#include <limits.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int n1 = nums1Size;
    int n2 = nums2Size;
    int low = 0, high = n1;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = (n1 + n2 + 1) / 2 - i;

        int L1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int R1 = (i == n1) ? INT_MAX : nums1[i];
        int L2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int R2 = (j == n2) ? INT_MAX : nums2[j];

        if (L1 <= R2 && L2 <= R1) {
            if ((n1 + n2) % 2 != 0) {
                return (double)MAX(L1, L2);
            } else {
                return (MAX(L1, L2) + MIN(R1, R2)) / 2.0;
            }
        } else if (L1 > R2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return 0.0;
}