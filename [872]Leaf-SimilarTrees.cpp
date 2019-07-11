/*
 * https://leetcode.com/problems/leaf-similar-trees/
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

void getLeafNodes(vector<int>& leaves, TreeNode* root)
{
   if (root == nullptr) return;
   if (root->left == nullptr && root->right == nullptr) leaves.push_back( root->val );
   getLeafNodes( leaves, root->left );
   getLeafNodes( leaves, root->right );
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) 
{
   vector<int> leaves1, leaves2;
   getLeafNodes( leaves1, root1 );
   getLeafNodes( leaves2, root2 );
   return leaves1 == leaves2;
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
   vector<int> nodes1 = { 1, 2, 3 };
   vector<int> nodes2 = { 1, 3, 2 };
   TreeNode* root1 = buildTree( nodes1 );
   TreeNode* root2 = buildTree( nodes2 );
   cout << leafSimilar( root1, root2 ) << endl;
   return 0;
}