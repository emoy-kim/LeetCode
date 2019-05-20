/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (40.88%)
 * Total Accepted:    263.2K
 * Total Submissions: 643.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 */

#include <iostream>

using namespace std;

struct ListNode 
{
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
   if (head == NULL) return head;

   ListNode* removed = head;
   ListNode* ptr = head;
   int curr_val = ptr->val;
   while (ptr->next != NULL) {
      if (curr_val != ptr->next->val) {
          curr_val = ptr->next->val;
          removed->next = ptr->next;
          removed = removed->next;
      }
      ptr = ptr->next;
   }
   removed->next = NULL;
   return head;
}