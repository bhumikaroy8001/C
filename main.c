
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    // Ensure nums1 is the smaller array for binary search efficiency
    if (nums1Size > nums2Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int total = m + n;
    int half = (total + 1) / 2; // Left partition size

    int left = 0;
    int right = m;

    while (left <= right)
    {
        // Partition nums1 at i
        int i = (left + right) / 2;
        // Partition nums2 at j such that i + j = half
        int j = half - i;

        // Handle edge cases for boundaries
        int nums1Left = (i > 0) ? nums1[i - 1] : INT_MIN;
        int nums1Right = (i < m) ? nums1[i] : INT_MAX;
        int nums2Left = (j > 0) ? nums2[j - 1] : INT_MIN;
        int nums2Right = (j < n) ? nums2[j] : INT_MAX;

        // Check if we found the correct partition
        if (nums1Left <= nums2Right && nums2Left <= nums1Right)
        {
            // Found the correct partition
            if (total % 2 == 1)
            {
                // Odd total length - median is max of left partition
                return (double)fmax(nums1Left, nums2Left);
            }
            else
            {
                // Even total length - median is average of max left and min right
                return ((double)fmax(nums1Left, nums2Left) + fmin(nums1Right, nums2Right)) / 2.0;
            }
        }
        else if (nums1Left > nums2Right)
        {
            // nums1's left partition is too big, move left
            right = i - 1;
        }
        else
        {
            // nums1's left partition is too small, move right
            left = i + 1;
        }
    }

    return 0.0; // Should never reach here for valid inputs
}