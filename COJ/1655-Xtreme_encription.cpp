/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@@live.com.mx>
   Link: http://coj.uci.cu/24h/problem.xhtml?pid=1655 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isSubsequence(string str1, string str2)
{
  stack<int> s;
  int str1Length = str1.length();
  int str2Length = str2.length();

  if(str1Length > str2Length) return false;

  for(int i = str1Length-1; i >= 0; i--)
    s.push(str1[i]);

  for(int i = 0; i < str2Length; i++)
  {
    if(s.top() == str2[i]) s.pop();
    if(s.empty()) return true;
  }

  return false;
}

int main()
{
  string str1, str2;
  while(cin >> str1 >> str2)
    puts(isSubsequence(str1, str2) ? "Yes" : "No");

  return 0;
}