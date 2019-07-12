/*
 * https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode 
{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(int& sum, int val, TreeNode* root)
{
   if (root == nullptr) return;
   if (root->left == nullptr && root->right == nullptr) {
      val = (val << 1) | root->val;
      sum += val;
   }
   dfs( sum, (val << 1) | root->val, root->left );
   dfs( sum, (val << 1) | root->val, root->right );
}

int sumRootToLeaf(TreeNode* root) 
{
   int sum = 0;
   dfs( sum, 0, root );
   return sum;
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

int main()
{
   vector<int> nodes = { 1, 0, 1, 0, 1, 0, 1 };
   TreeNode* root = buildTree( nodes );
   cout << sumRootToLeaf( root ) << endl;
   return 0;
}