/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (47.13%)
 * Total Accepted:    209.3K
 * Total Submissions: 444K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode* createBST(vector<int>& nums, int start, int end)
{
   if (start > end) return NULL;
   if (start == end) return new TreeNode(nums[start]);

   const int mid = (start + end) / 2;
   TreeNode* node = new TreeNode(nums[mid]);
   node->left = createBST( nums, start, mid - 1 );
   node->right = createBST( nums, mid + 1, end );
   return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) 
{
   if (nums.empty()) return NULL;
   return createBST( nums, 0, nums.size() - 1 );
}