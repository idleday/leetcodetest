#ifndef SORT_HH
#define SORT_HH

#include <vector>
#include <map>
#include <string>

using namespace std;

void insert_sort(vector<int> &a, int n);
void insert_sort(vector<int> &a, vector<int> &b);

string longestPalindrome(string s);
string convert2shapeZ(string s, int numRows);
string simplifyPattern(string p);
bool isMatch(string s, string p);
void stringTest();

#endif // SORT_HH
