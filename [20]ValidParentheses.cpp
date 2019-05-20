/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.59%)
 * Total Accepted:    399.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

#include <iostream>
#include <map>
#include <stack>

using namespace std;

bool isValid(string s) 
{
   map<char, int> dic;
   dic['('] = -1;
   dic['{'] = -2;
   dic['['] = -3;
   dic[')'] = 1;
   dic['}'] = 2;
   dic[']'] = 3;

   bool result = true;
   stack<int> op;
   for (int i = 0; i < s.length(); ++i) {
      result = false;
      const int val = dic[s[i]];
      
      if (val < 0) {
          op.push( val );
      }
      else {
          if (op.empty() || val + op.top() != 0) {
              break;
          }
          op.pop();
          result = true;
      }
   }
   if (op.empty()) return result;
   return false;
}