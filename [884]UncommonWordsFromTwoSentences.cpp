/*
 * https://leetcode.com/problems/uncommon-words-from-two-sentences/
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void parseWithSpace(vector<string>& parsed, const string& str)
{
   const string delimiter = " ";
   size_t start = 0, end = 0;
   while ((end = str.find( delimiter, start )) != string::npos) {
      parsed.emplace_back( str.substr( start, end - start ) );
      start = end + 1;
   }
   parsed.emplace_back( str.substr( start ) );
}

vector<string> uncommonFromSentences(string A, string B) 
{
   vector<string> setA, setB;
   parseWithSpace( setA, A );
   parseWithSpace( setB, B );
   
   unordered_map<string, int> table;
   for (auto& str : setA) {
      const auto it = table.find( str );
      if (it != table.end()) it->second++;
      else table[str] = 0;
   }
   for (const auto& str : setB) {
      const auto it = table.find( str );
      if (it != table.end()) it->second++;
      else table[str] = 0;
   }

   vector<string> uncommon;
   for (const auto& it : table) {
      if (it.second == 0) {
          uncommon.push_back( it.first );    
      }
   }
   return uncommon;
}

int main()
{
   const string A = "this apple is sweet";
   const string B = "this apple is sour";
   vector<string> uncommon = uncommonFromSentences( A, B );
   for (const auto& i : uncommon) {
      cout << i.c_str() << endl;
   }
   return 0;
}