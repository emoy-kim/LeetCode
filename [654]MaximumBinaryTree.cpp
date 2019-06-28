/*
 * https://leetcode.com/problems/maximum-binary-tree/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& nums, int left, int right)
{
   if (left >= right) return nullptr;

   int root_val = INT_MIN, root_index = -1;
   for (int i = left; i < right; ++i) {
      if (root_val < nums[i]) {
          root_val = nums[i];
          root_index = i;
      }
   }
   auto* root = new TreeNode( root_val );
   root->left = buildTree( nums, left, root_index );
   root->right = buildTree( nums, root_index + 1, right );
   return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
{
   return buildTree( nums, 0, nums.size() );
}

void printTreeNodes(TreeNode* root)
{
   queue<TreeNode*> visit;
   visit.push( root );

   while (!visit.empty()) {
      TreeNode* node = visit.front();
      visit.pop();

      cout << node->val << " ";
      if (node->left != nullptr) visit.push( node->left );
      if (node->right != nullptr) visit.push( node->right );
   }
   cout << endl;
}

int main()
{
   vector<int> nums = { 3, 2, 1, 6, 0, 5 };
   printTreeNodes( constructMaximumBinaryTree( nums ) );
   return 0;
}