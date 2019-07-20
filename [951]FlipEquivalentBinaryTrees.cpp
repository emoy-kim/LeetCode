/*
 * https://leetcode.com/problems/flip-equivalent-binary-trees/
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

bool flipEquiv(TreeNode* root1, TreeNode* root2) 
{
   if (!root1 && !root2) return true;
   if (!root1 && root2 || root1 &&!root2 || root1->val != root2->val) return false;
   return 
      flipEquiv( root1->left, root2->left ) && flipEquiv( root1->right, root2->right )
      || flipEquiv( root1->right, root2->left ) && flipEquiv( root1->left, root2->right );
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
   vector<int> nodes1 = { 1,2,3,4,5,6,-1,-1,-1,7,8 };
   vector<int> nodes2 = { 1,3,2,-1,6,4,5,-1,-1,-1,-1,8,7 };
   TreeNode* root1 = buildTree( nodes1 );
   TreeNode* root2 = buildTree( nodes2 );
   cout << flipEquiv( root1, root2 ) <<endl;
   return 0;
}