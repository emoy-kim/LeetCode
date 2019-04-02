/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (53.83%)
 * Total Accepted:    315.3K
 * Total Submissions: 585.8K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addRecursively(vector<string>& results, const string& str, const int& left, const int& right)
{
   if (left == 0 && right == 0) {
      results.push_back( str );
      return;
   }

   if (left > 0) addRecursively( results, str + "(", left - 1, right );
   if (left < right) addRecursively( results, str + ")", left, right - 1 );
}

vector<string> generateParenthesis(int n) 
{
   vector<string> results;
   addRecursively( results, "(", n - 1, n );
   return results;
}

int main()
{
   const vector<string> combinations = generateParenthesis( 3 );
   for (const auto& str : combinations) {
      cout << str << endl;
   }
   return 0;
}