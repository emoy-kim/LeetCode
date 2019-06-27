/*
 * https://leetcode.com/problems/remove-outermost-parentheses/
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeOuterParentheses(string S) 
{
   stack<char> p_stack;
   string removed;
   for (const auto& c : S) {
      if (c == '(') {
          if (!p_stack.empty()) removed += "(";
          p_stack.push( c );
      }
      else {
          p_stack.pop();
          if (!p_stack.empty()) removed += ")";
      }
   }
   return removed;
}

int main()
{
   cout << removeOuterParentheses( "(()())(())(()(()))" ).c_str() << endl;
   return 0;
}