/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (49.96%)
 * Total Accepted:    191.6K
 * Total Submissions: 383.4K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * 
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ZY"
 * Output: 701
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string s) {
   const int len = s.length();
   int label = 1;
   for (int i = 0; i < len - 1; ++i) {
      label *= 26;
   }
   label = (label - 1) / 25;
   label *= 26;

   int base = 26;
   for (int i = len - 2; i >= 0; --i) {
      int d = s[i] - 'A';
      label += base * d;
      base *= 26;
   }
   label += s[len - 1] - 'A' + 1;
   return label;
}