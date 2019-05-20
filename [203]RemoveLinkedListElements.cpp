#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) 
{
   if (head == NULL) return NULL;

   while (head && head->val == val) {
      head = head->next;
   }

   ListNode* curr = head;
   ListNode* prev = curr;
   while (curr) {
      if (curr->val == val) {
          prev->next = curr->next;
          curr = prev->next;
      }
      else {
          prev = curr;
          curr = curr->next;
      }
   }
   return head;
}