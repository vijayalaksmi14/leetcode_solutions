#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Test Case 1: Standard Case (Element Present)
    int nums1[] = {-1, 0, 3, 5, 9, 12};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 9;
    printf("Test 1 Output: %d (Expected: 4)\n", search(nums1, size1, target1));

    // Test Case 2: Edge Case (Element Not Present / Single Element)
    int nums2[] = {5};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = -5;
    printf("Test 2 Output: %d (Expected: -1)\n", search(nums2, size2, target2));

    return 0;
}