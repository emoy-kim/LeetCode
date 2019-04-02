/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.85%)
 * Total Accepted:    363.5K
 * Total Submissions: 889.8K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> letterCombinations(string digits) 
{
   map<char, string> mapper = {
      { '0', " " },
      { '1', "*" },
      { '2', "abc" },
      { '3', "def" },
      { '4', "ghi" },
      { '5', "jkl" },
      { '6', "mno" },
      { '7', "pqrs" },
      { '8', "tuv" },
      { '9', "wxyz" }
   };

   vector<string> results;
   for (const auto& c : mapper[digits[0]]) {
      results.emplace_back( 1, c );
   }

   for (size_t d = 1; d < digits.size(); ++d) {
      const string str_to_be_added = mapper[digits[d]];
      const size_t old_size = results.size();
      for (size_t i = 0; i < old_size; ++i) {
         for (const auto& c : str_to_be_added) {
            results.push_back( results[i] + c );
         }
      }
      results.erase( results.begin(), results.begin() + old_size );
   }
   return results;
}

int main()
{
   const string digits("234");
   const vector<string> combinations = letterCombinations( digits );
   for (const auto& str : combinations) {
      cout << str << endl;
   }
   return 0;
}