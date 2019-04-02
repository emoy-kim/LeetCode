/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (33.56%)
 * Total Accepted:    360.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(const vector<int>& values)
{
   if (values.empty()) return nullptr;

   auto* head = new ListNode(values[0]);
   ListNode* node = head;
   for (size_t i = 1; i < values.size(); ++i) {
      node->next = new ListNode(values[i]);
      node = node->next;
   }
   return head;
}

int findMinimumAndMoveItsPointer(vector<ListNode*>& lists)
{
   int min_index = -1;
   int minimum = numeric_limits<int>::max();
   for (size_t i = 0; i < lists.size(); ++i) {
      if (lists[i] != nullptr && lists[i]->val <= minimum) {
         min_index = i;
         minimum = lists[i]->val;
      }
   }
   if (min_index >= 0) {
      lists[min_index] = lists[min_index]->next;
   }
   return minimum;
}

bool isDone(vector<ListNode*>& lists)
{
   bool done = true;
   for (const auto& list : lists) {
      done &= list == nullptr;
   }
   return done;
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
   if (lists.empty() || isDone( lists )) return nullptr;

   auto* head = new ListNode(findMinimumAndMoveItsPointer( lists ));
   ListNode* node = head;
   while (!isDone( lists )) {
      node->next = new ListNode(findMinimumAndMoveItsPointer( lists ));
      node = node->next;
   }
   return head;
}

int main()
{
   vector<ListNode*> lists = {
      //createList( {} ),
      createList( { 1, 4, 5 } ),
      createList( { 1, 3, 4 } ),
      createList( { 2, 6 } ),
   };

   ListNode* merged = mergeKLists( lists );
   while (merged != nullptr) {
      cout << merged->val << " ";
      merged = merged->next;
   }
   cout << endl;
   return 0;
}