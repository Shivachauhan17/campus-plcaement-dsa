#include<iostream>
using namespace std;


//Better:- you can try from hashing -> store adresses

//Optimal:- find the length of both linked list-> skip the node of longer linked list equal to difference of length
//-> then check the if nodes of linked list pointing to same address


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0;
        int len2=0;
        ListNode *l1=headA;
        ListNode *l2=headB;

        while(l1!=NULL){
            len1++;
            l1=l1->next;
        }
        while(l2!=NULL){
            len2++;
            l2=l2->next;
        }
        l1=headA;
        l2=headB;
        int diff=abs(len1-len2);
        while(diff!=0){
            if(len1>len2){
                l1=l1->next;
            }
            else{
                l2=l2->next;
            }
            diff--;
        }
        ListNode *ans=l1;
        while(l1->next!=NULL){
            if(l1->next==l2->next){
                ans=l1->next;
                break;
            }
            l1=l1->next;
            l2=l2->next;
        }
        return ans;
    }
};