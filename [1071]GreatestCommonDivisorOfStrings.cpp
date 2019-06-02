/*
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0) {
		const int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

string gcdOfStrings(string str1, string str2) 
{
	if (str1.length() < str2.length()) swap( str1, str2 );

	const int l1 = str1.length();
	const int l2 = str2.length();
	const int g = gcd( l1, l2 );

	string x = str1.substr( 0, g );
	for (int i = 0; i < l1; i += g) {
		if (str1.substr( i, g ) != x) return "";
	}
	for (int i = 0; i < l2; i += g) {
		if (str2.substr( i, g ) != x) return "";
	}
	return x;
}

int main()
{
	string str1 = "ABCABCABCABCABC";
	string str2 = "ABCABCABC";
	cout << gcdOfStrings( str1, str2 ).c_str() << endl;
	return 0;
}