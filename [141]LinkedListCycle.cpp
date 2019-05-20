
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

bool hasCycle(ListNode *head) 
{
   if (head == nullptr) return false;

   ListNode* slow = head;
   ListNode* fast = head->next;

   while (fast != nullptr) {
      if (slow == fast) return true;
      
      slow = slow->next;
      fast = fast->next;
      if (fast != nullptr) fast = fast->next;
   }
   return false;
}