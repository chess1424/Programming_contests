#include <iostream>

using namespace std;

int main()
{
  int t, left, right, ans;
  string str;
  
  scanf("%d",&t);

  while(t--)
  {
    cin >> str;
    
    left = ans =  0;
    right = str.length() - 1;

    while(left <= right) 
      ans += abs( str[left++] - str[right--] );

    printf("%d\n", ans); 
  }
  
  return 0;
}
