#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to partition the linked list
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode less_dummy = {0, NULL};  // Dummy node for the "less" list
    struct ListNode great_dummy = {0, NULL}; // Dummy node for the "greater or equal" list

    struct ListNode* less = &less_dummy;
    struct ListNode* great = &great_dummy;

    while (head) {
        if (head->val < x) {
            less->next = head;
            less = head;
        } else {
            great->next = head;
            great = head;
        }
        head = head->next;
    }

    less->next = great_dummy.next; // Connect the "less" list to the "greater or equal" list
    great->next = NULL; // Terminate the "greater or equal" list

    return less_dummy.next; // Return the head of the "less" list
}

// Helper function to create a linked list from an array
struct ListNode* createLinkedList(int* values, int size) {
    if (size == 0) return NULL;

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = values[0];
    head->next = NULL;

    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = values[i];
        current->next = NULL;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) {
            printf(",");
        }
        head = head->next;
    }
    printf("]\n");
}

// Main function to test the partition function
int main() {
    // Example 1
    int values1[] = {1, 4, 3, 2, 5, 2};
    int x1 = 3;
    struct ListNode* head1 = createLinkedList(values1, sizeof(values1) / sizeof(values1[0]));
    printf("Input: head = [1,4,3,2,5,2], x = %d\n", x1);
    struct ListNode* result1 = partition(head1, x1);
    printf("Output: ");
    printLinkedList(result1);

    // Example 2
    int values2[] = {2, 1};
    int x2 = 2;
    struct ListNode* head2 = createLinkedList(values2, sizeof(values2) / sizeof(values2[0]));
    printf("Input: head = [2,1], x = %d\n", x2);
    struct ListNode* result2 = partition(head2, x2);
    printf("Output: ");
    printLinkedList(result2);

    return 0;
}
