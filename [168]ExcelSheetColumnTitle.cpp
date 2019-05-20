/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (28.05%)
 * Total Accepted:    153.5K
 * Total Submissions: 547.2K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 */

#include <iostream>
#include <string>

using namespace std;

std::string convertToTitle(int n) {
   int dim = 1;
   int vlm = 26;
   int x = n;
   const int overflow = INT_MAX / 26 + 1;
   bool is_bndry = false;
   while (x > vlm) {
      x -= vlm;
      dim++;
      if (vlm >= overflow) {
          is_bndry = true;
          break;
      }
      vlm *= 26;
   }

   x--;
   if (!is_bndry) vlm /= 26;

   string result;
   for (int d = dim - 1; d > 0; --d) {
      const int digit = x / vlm;
      result += 'A' + static_cast<char>(digit);
      x -= digit * vlm;
      vlm /= 26;
   }
   result += 'A' + static_cast<char>(x); 
   return result;
}