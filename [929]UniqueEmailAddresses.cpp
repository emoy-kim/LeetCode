/*
 * https://leetcode.com/problems/unique-email-addresses/
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int numUniqueEmails(vector<string>& emails) 
{
   unordered_set<string> addresses;
   for (const auto& name : emails) {
      string address;
      const int at_pos = name.find( "@" );
      for (int i = 0; i < at_pos; ++i) {
          if (name[i] == '.') continue;
          if (name[i] == '+') break;
          address += name[i];
      }
      address += name.substr( at_pos );
      addresses.insert( address );
   }
   return addresses.size();
}

int main()
{
   vector<string> emails = {
      "test.email+alex@leetcode.com",
      "test.e.mail+bob.cathy@leetcode.com",
      "testemail+david@lee.tcode.com"
   };
   cout << numUniqueEmails( emails ) << endl;
}