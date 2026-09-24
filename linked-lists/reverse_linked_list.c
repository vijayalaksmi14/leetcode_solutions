#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse the linked list in-place
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;  // 1. Store the next node pointer
        curr->next = prev;  // 2. Reverse the current node's pointer
        prev = curr;        // 3. Move prev forward to current node
        curr = next;        // 4. Move curr forward to next node
    }

    return prev; // prev is now the new head of the reversed list
}

// Helper function to dynamically allocate and create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    printf("[");
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d%s", curr->val, curr->next ? " -> " : "");
        curr = curr->next;
    }
    printf("]\n");
}

int main() {
    // Test Case 1: Standard Case ([1 -> 2 -> 3])
    struct ListNode* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    printf("Test 1 Original: ");
    printList(head1);
    head1 = reverseList(head1);
    printf("Test 1 Reversed: ");
    printList(head1); // Expected output: [3 -> 2 -> 1]

    // Test Case 2: Edge Case (Single Node [5])
    struct ListNode* head2 = createNode(5);

    printf("\nTest 2 Original: ");
    printList(head2);
    head2 = reverseList(head2);
    printf("Test 2 Reversed: ");
    printList(head2); // Expected output: [5]

    return 0;
}