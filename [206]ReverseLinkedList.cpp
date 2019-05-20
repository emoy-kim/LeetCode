/*
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (50.18%)
 * Total Accepted:    439.6K
 * Total Submissions: 876.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 // recursive version
 ListNode* reverseRecursive(ListNode* head)
 {
     if (head->next == NULL) return head;

     ListNode* end_node = reverseRecursive( head->next );
     head->next->next = head;
     head->next = NULL;
     return end_node;
 }

 // iterative version
 ListNode* reverseIterative(ListNode* head)
 {
     stack<ListNode*> nodes;
     ListNode* node = head;
     while (node != NULL) {
         nodes.push( node );
         node = node->next;
     }
     
     ListNode* reversed = nodes.top();
     node = reversed;
     nodes.pop();

     while (!nodes.empty()) {
         node->next = nodes.top();
         nodes.pop();
         node = node->next;
     }
     node->next = NULL;
     return reversed;
 }

 ListNode* reverseList(ListNode* head) {
     if (head == NULL) return NULL;
     //return reverseRecursive( head );
     return reverseIterative( head );
 }