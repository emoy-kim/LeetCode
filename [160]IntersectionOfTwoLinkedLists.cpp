/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (30.77%)
 * Total Accepted:    237.3K
 * Total Submissions: 771.4K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists: 
 * 
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗            
 * B:     b1 → b2 → b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns. 
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * 
 * 
 * 
 * Credits:Special thanks to @stellari for adding this problem and creating all
 * test cases.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
   int lenA = 0;
   ListNode* nodeA = headA;
   while (nodeA != NULL) {
      nodeA = nodeA->next;
      lenA++;
   }

   int lenB = 0;
   ListNode* nodeB = headB;
   while (nodeB != NULL) {
      nodeB = nodeB->next;
      lenB++;
   }

   nodeA = headA;
   nodeB = headB;
   const int diff = abs( lenA - lenB );
   if (lenA > lenB) {
      for (int i = 0; i < diff; ++i) {
          nodeA = nodeA->next;
      }
   }
   else {
      for (int i = 0; i < diff; ++i) {
          nodeB = nodeB->next;
      }
   }

   while (nodeA != nodeB) {
      nodeA = nodeA->next;
      nodeB = nodeB->next;
   }
   return nodeA;
}