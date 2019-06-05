/*
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252273/C%2B%2B-O(n-log-n)
TreeNode* bstFromPreorder(vector<int>& preorder, int first = 0, int last = 0) 
{
   if (last == 0) last = preorder.size();
   if (first == last) return nullptr;
   const auto split = find_if(
      preorder.begin() + first, preorder.begin() + last, 
      [&](int val) { return val > preorder[first]; }
   );
   const auto root = new TreeNode(preorder[first]);
   root->left = bstFromPreorder( preorder, first + 1, split - preorder.begin() );
   root->right = bstFromPreorder( preorder, split - preorder.begin(), last );
   return root;
}

int main()
{
   vector<int> preorder = { 8,5,1,7,10,12 };
   TreeNode* tree = bstFromPreorder( preorder );

   queue<TreeNode*> visit;
   visit.push( tree );
   while (!visit.empty()) {
      TreeNode* node = visit.front();
      visit.pop();

      cout << node->val << " ";
      if (node->left != nullptr) visit.push( node->left );
      if (node->right != nullptr) visit.push( node->right );
   }
   cout << endl;
   return 0;
}