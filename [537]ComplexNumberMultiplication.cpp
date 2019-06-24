/*
 * https://leetcode.com/problems/complex-number-multiplication/
 */

#include <iostream>
#include <string>

using namespace std;

string complexNumberMultiply(string a, string b) 
{
   const int a_plus_pos = a.find( "+" );
   const int b_plus_pos = b.find( "+" );
   const int p = stoi( a.substr( 0, a_plus_pos ) );
   const int q = stoi( a.substr( a_plus_pos + 1, a.length() - 1 ) );
   const int r = stoi( b.substr( 0, b_plus_pos ) );
   const int s = stoi( b.substr( b_plus_pos + 1, b.length() - 1 ) );
   const string multiplied = to_string( p * r - q * s ) + "+" + to_string( p * s + q * r ) + "i";
   return multiplied;
}

int main()
{
   cout << complexNumberMultiply( "1+-1i", "1+-1i" ).c_str() << endl;
   return 0;
}