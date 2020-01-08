#include <iostream>
#include <list>

using namespace std;

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    
    ListNode* progresses(ListNode* l1, ListNode* l2, bool carry) {
       int val;
       ListNode* temp;
       if(carry){
           if(l1 == NULL && l2 == NULL){
               temp = new ListNode(1);
               return temp;
           }
           else if(l1 == NULL){
               temp = new ListNode((1+l2->val) % 10);
               temp-> next = progresses(NULL,l2->next,(1 + l2->val) > 9);
               return temp;
           }
           else if(l2 == NULL){
               temp = new ListNode((1+l1->val) % 10);
               temp-> next = progresses(l1->next,NULL,(1 + l1->val) > 9);
               return temp;
           }
           else{
               temp = new ListNode((1+l2->val+l1->val) % 10);
               temp-> next = progresses(l1->next,l2->next,(1 + l2->val + l1->val) > 9);
               return temp;
           }
       }
       else{
           if(l1 == NULL && l2 == NULL){
               return NULL;
           }
           else if(l1 == NULL){
               temp = new ListNode((l2->val) % 10);
               temp-> next = progresses(NULL,l2->next,( l2->val) > 9);
               return temp;
           }
           else if(l2 == NULL){
               temp = new ListNode((l1->val) % 10);
               temp-> next = progresses(l1->next,NULL,( l1->val) > 9);
               return temp;
           }
           else{
               temp = new ListNode((l2->val+l1->val) % 10);
               temp-> next = progresses(l1->next,l2->next,(l2->val + l1->val) > 9);
               return temp;
           }
       }
       return NULL;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       return progresses(l1, l2, 0);
    }
};