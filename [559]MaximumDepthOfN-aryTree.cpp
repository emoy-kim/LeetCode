/*
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int maxDepth(Node* root) 
{
   int max_depth = 0;
   if (root) {
      for (const auto& n : root->children) {
          max_depth = max( max_depth, maxDepth( n ) );
      }
      max_depth++;
   }
   return max_depth;
}