/*
 * https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sufficientSubset(TreeNode* root, int limit) 
{
   if (root->left == nullptr && root->right == nullptr) return root->val < limit ? nullptr : root;
   if (root->left != nullptr) root->left = sufficientSubset( root->left, limit - root->val );
   if (root->right != nullptr) root->right = sufficientSubset( root->right, limit - root->val );
   return root->left == nullptr && root->right == nullptr ? nullptr : root;
}

TreeNode* buildTree(vector<int>& nodes)
{
   auto* root = new TreeNode(nodes[0]);
   
   queue<TreeNode*> visit;
   visit.push( root );
   int index = 1;
   const int size = nodes.size();
   while (!visit.empty()) {
      TreeNode* node = visit.front();
      visit.pop();

      if (index < size && nodes[index] >= 0) {
         node->left = new TreeNode(nodes[index]);
         visit.push( node->left );
      }
      index++;
      if (index < size && nodes[index] >= 0) {
         node->right = new TreeNode(nodes[index]);
         visit.push( node->right );
      }
      index++;
   }
   return root;
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
   vector<int> nodes = { 1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14 };
   TreeNode* root = buildTree( nodes );
   printTreeNodes( sufficientSubset( root, 1 ) );
   return 0;
}