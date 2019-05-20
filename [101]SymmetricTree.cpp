/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (41.63%)
 * Total Accepted:    309.4K
 * Total Submissions: 743.2K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode 
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursive version
bool isSameTree(TreeNode* p, TreeNode* q)
{
   if (p == NULL || q == NULL) return p == q;
   if (p->val != q->val) return false;

   return isSameTree( p->left, q->right ) && isSameTree( p->right, q->left );
}

// iterative version
bool isMirrorTree(TreeNode* p, TreeNode* q)
{
   stack<TreeNode*> p_visited, q_visited;
   p_visited.push( p );
   q_visited.push( q );

   while (!p_visited.empty() && !q_visited.empty()) {
      TreeNode* p_node = p_visited.top();
      TreeNode* q_node = q_visited.top();
      p_visited.pop();
      q_visited.pop();

      if (p_node == NULL || q_node == NULL) {
          if (p_node == NULL && q_node == NULL) continue;
          return false;
      }
      if (p_node->val != q_node->val) return false;

      p_visited.push( p_node->left );
      p_visited.push( p_node->right );
      q_visited.push( q_node->right );
      q_visited.push( q_node->left );
   }
   return p_visited.empty() && q_visited.empty();
}

bool isSymmetric(TreeNode* root) {
   if (root == NULL) return true;

   //return isSameTree( root->left, root->right );
   return isMirrorTree( root->left, root->right );
}