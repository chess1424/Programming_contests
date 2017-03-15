#include <iostream>
#include <vector>

using namespace std;

/*
kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based )

NOTE:
You are not allowed to modify the array ( The array is read only ).
Try to do it using constant extra space.
*/

int f(const int target, const vector<int> &A, const int k)
{
  int index = 0;
  for(int i = 0; i < A.size(); i++)
    index += (A[i] <= target);

  return index > k;
}

int solve(const vector<int> &A, const int k)
{
  int ans = (1<<30) - 1;
  for(int i = 29; i >=0; i--)
    ans ^= f(ans ^ (1<<i), A, k-1) << i;

  return ans;
}

int main()
{
  vector<int> A = {2, 1, 4, 3, 2};
  int k = 3;

  cout << solve(A, k) << endl;
  return 0;
}