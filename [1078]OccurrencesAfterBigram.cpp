/*
 * https://leetcode.com/problems/occurrences-after-bigram/
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

vector<string> findOccurrences(string text, string first, string second) 
{
   istringstream iss(text);
   vector<std::string> parsed((istream_iterator<string>(iss)),
                            istream_iterator<string>());

   vector<string> thirds;
   for (size_t i = 0; i < parsed.size() - 2; ++i) {
      if (parsed[i] == first && parsed[i + 1] == second) {
         thirds.push_back( parsed[i + 2] );
      }
   }
   return thirds;
}

int main()
{
   const string text = "we will we will rock you";
   const string first = "we";
   const string second = "will";
   vector<string> thirds = findOccurrences( text, first, second );
   for (const auto& i : thirds) {
      cout << i.c_str() << " ";
   }
   cout << endl;
}