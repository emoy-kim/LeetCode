/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 *
 * https://leetcode.com/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (47.84%)
 * Total Accepted:    195.5K
 * Total Submissions: 408.5K
 * Testcase Example:  '["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]\n[[[7,3,15,null,null,9,20]],[null],[null],[null],[null],[null],[null],[null],[null],[null]]'
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // return 3
 * iterator.next();    // return 7
 * iterator.hasNext(); // return true
 * iterator.next();    // return 9
 * iterator.hasNext(); // return true
 * iterator.next();    // return 15
 * iterator.hasNext(); // return true
 * iterator.next();    // return 20
 * iterator.hasNext(); // return false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * next() and hasNext() should run in average O(1) time and uses O(h) memory,
 * where h is the height of the tree.
 * You may assume that next() call will always be valid, that is, there will be
 * at least a next smallest number in the BST when next() is called.
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
   vector<int> heap;

public:
   BSTIterator(TreeNode* root) {
      if (root == nullptr) return;

      queue<TreeNode*> visit;
      visit.push( root );

      while (!visit.empty()) {
         TreeNode* ptr = visit.front();
         heap.push_back( ptr->val );
         visit.pop();

         if (ptr->left != nullptr) visit.push( ptr->left );
         if (ptr->right != nullptr) visit.push( ptr->right );
      }

      make_heap( heap.begin(), heap.end(), greater<int>() );
   }

   /** @return the next smallest number */
   int next() {
      pop_heap( heap.begin(), heap.end(), greater<int>() );
      const int val = heap.back();
      heap.pop_back();
      return val;
   }

   /** @return whether we have a next smallest number */
   bool hasNext() {
      return !heap.empty();  
   }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
   auto* root = new TreeNode(3);
   root->left = new TreeNode(7);
   root->right = new TreeNode(15);
   root->right->left = new TreeNode(9);
   root->right->right = new TreeNode(20);

   auto* iterator = new BSTIterator(root);
   cout << iterator->next() << endl;    // return 3
   cout << iterator->next() << endl;    // return 7
   cout << iterator->hasNext() << endl; // return true
   cout << iterator->next() << endl;    // return 9
   cout << iterator->hasNext() << endl; // return true
   cout << iterator->next() << endl;    // return 15
   cout << iterator->hasNext() << endl; // return true
   cout << iterator->next() << endl;    // return 20
   cout << iterator->hasNext() << endl; // return false

   return 0;
}