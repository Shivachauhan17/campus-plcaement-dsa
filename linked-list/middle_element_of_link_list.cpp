#include<iostream>
using namespace std;

//Efficient:- Tortoise-Hare approach
//using slow pointer and fast pointer 
//till the end slow pointer coveers the half traversal of what fast pointer covers
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};