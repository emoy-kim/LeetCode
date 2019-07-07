/*
 * https://leetcode.com/problems/defanging-an-ip-address/
 */

#include <iostream>
#include <string>

using namespace std;

string defangIPaddr(string address) 
{
   size_t pos = 0, found = string::npos;
   while ((found = address.substr( pos ).find( "." )) != string::npos) {
      address.replace( pos + found, 1, "[.]" );
      pos += found + 3;
   }
   return address;
}

int main()
{
   string address = "255.100.50.0";
   cout << defangIPaddr( address ).c_str() << endl;
   return 0;
}