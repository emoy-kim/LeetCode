/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (43.12%)
 * Total Accepted:    408K
 * Total Submissions: 946.2K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode 
{
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
   vector<int> list1, list2;

   ListNode* ptr = l1;
   while (ptr != NULL) {
      list1.push_back( ptr->val );
      ptr = ptr->next;
   }

   ptr = l2;
   while (ptr != NULL) {
      list2.push_back( ptr->val );
      ptr = ptr->next;
   }

   list1.insert( list1.end(), list2.begin(), list2.end() );

   if (list1.empty()) return NULL;

   sort( list1.begin(), list1.end() );

   ListNode* result = new ListNode(list1[0]);
   ListNode* head = result;
<<<<<<< HEAD
   for (size_t i = 1; i < list1.size(); ++i) {
=======
   for (uint i = 1; i < list1.size(); ++i) {
>>>>>>> ec63630dcc27e66370f52497e716152759676e8d
      head->next = new ListNode(list1[i]);
      head = head->next;
   }

   return result;
}