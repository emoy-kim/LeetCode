/*
 * https://leetcode.com/problems/subdomain-visit-count/
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) 
{
   unordered_map<string, int> table;
   for (const auto& d : cpdomains) {
      const int blank_pos = d.find( " " );
      int count = stoi( d.substr( 0, blank_pos ) );
      const int first_dot_pos = d.find( ".", blank_pos + 1 );
      const int second_dot_pos = d.find( ".", first_dot_pos + 1 );
      
      const string str1 = d.substr( blank_pos + 1 );
      if (table.find( str1 ) != table.end()) table[str1] += count;
      else table[str1] = count;
      
      const string str2 = d.substr( first_dot_pos + 1 );
      if (table.find( str2 ) != table.end()) table[str2] += count;
      else table[str2] = count;
      
      if (second_dot_pos >= 0) {
          const string str3 = d.substr( second_dot_pos + 1 );
          if (table.find( str3 ) != table.end()) table[str3] += count;
          else table[str3] = count;
      }
   }

   vector<string> subdomains;
   for (const auto& t : table) {
      subdomains.push_back( to_string( t.second ) + " " + t.first );
   }
   return subdomains;
}

int main()
{
   vector<string> cpdomains = {
      "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"
   };
   vector<string> subdomains = subdomainVisits( cpdomains );
   for (const auto& d : subdomains) {
      cout << d << " ";
   }
   cout << endl;
   return 0;
}