#include <iostream>
#include <sstream>

using namespace std;

int n, m;

bool borde(int i, int j)
{
  if(i == 0 || j == 0 || i == n-1 || j == m-1) return true;

  return false;
}

string square(int num, int size)
{
  stringstream ss;
  ss << num;
  string num_str = ss.str(),  out = "";
  for(int i = 0; i < size - num_str.length(); i++) out += '.';
  out += num_str;
  return out;
}

int main()
{
  while(scanf("%d %d",&n, &m) != EOF)
  {
    int arr[n][m], anillo = 0, size, count_T = 0;
    string str, empty_square;

    for(int i = 0; i < n; i++)
    {
      cin >> str;
      for(int j = 0; j < str.length(); j++)
      {
        if(str[j] == '.')
          arr[i][j] = 0;
        else
        {
          arr[i][j] = -1;
          count_T++;
        }
      }
    }

    while(count_T)
    {
      ++anillo;
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          if(arr[i][j] == -1) 
            if(borde(i,j)) 
            { arr[i][j] = 1; count_T--; }
            else if(arr[i-1][j] == anillo-1 || arr[i][j+1] == anillo-1 || arr[i+1][j] == anillo-1 || arr[i][j-1] == anillo-1)
            { arr[i][j] = anillo; count_T--; }  
    }

    if(anillo < 10)
    {
      size = 2;
      empty_square = "..";
    }
    else
    {
      size = 3;
      empty_square = "...";
    }

    for(int i = 0; i < n; i++)
    {
      str = "";
      for(int j = 0; j < m; j++)
        str += (arr[i][j] == 0) ? empty_square : square(arr[i][j] , size);
      cout << str << '\n';
    }

  }
  return 0;
}
