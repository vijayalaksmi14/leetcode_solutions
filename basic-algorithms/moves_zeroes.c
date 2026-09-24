#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int lastNonZero = 0;

    // Shift all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[lastNonZero];
            nums[lastNonZero] = nums[i];
            nums[i] = temp;
            lastNonZero++;
        }
    }
}

// Helper function to print array output for verification
void printArray(int* nums, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", nums[i], (i < size - 1) ? ", " : "");
    }
    printf("]\n");
}

int main() {
    // Test Case 1: Standard Case
    int nums1[] = {0, 1, 0, 3, 12};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    moveZeroes(nums1, size1);
    printf("Test 1 Output: ");
    printArray(nums1, size1); // Expected: [1, 3, 12, 0, 0]

    // Test Case 2: Edge Case (All Zeroes)
    int nums2[] = {0, 0, 0};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    moveZeroes(nums2, size2);
    printf("Test 2 Output: ");
    printArray(nums2, size2); // Expected: [0, 0, 0]

    return 0;
}