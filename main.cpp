#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0); // Dummy node for the "before" list
        ListNode afterHead(0);  // Dummy node for the "after" list
        ListNode* before = &beforeHead;
        ListNode* after = &afterHead;

        // Traverse the original list and partition nodes
        while (head) {
            if (head->val < x) {
                before->next = head;
                before = head;
            } else {
                after->next = head;
                after = head;
            }
            head = head->next;
        }

        after->next = nullptr; // Terminate the "after" list
        before->next = afterHead.next; // Connect the "before" list with the "after" list

        return beforeHead.next; // Return the head of the new list
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << ",";
        }
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> values1 = {1, 4, 3, 2, 5, 2};
    int x1 = 3;
    ListNode* head1 = createLinkedList(values1);
    cout << "Input: head = [1,4,3,2,5,2], x = " << x1 << endl;
    ListNode* result1 = solution.partition(head1, x1);
    cout << "Output: ";
    printLinkedList(result1);

    // Example 2
    vector<int> values2 = {2, 1};
    int x2 = 2;
    ListNode* head2 = createLinkedList(values2);
    cout << "Input: head = [2,1], x = " << x2 << endl;
    ListNode* result2 = solution.partition(head2, x2);
    cout << "Output: ";
    printLinkedList(result2);

    return 0;
}
