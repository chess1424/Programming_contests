#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  int t, o1, o2=0, size, d;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&o1, &o2);
    size = o1 * o2;

    int arr[size + size], count = 0;
    int arr_aux[size];

    for(int i = 0; i < size; i++)
    {
      scanf("%d",&d);
      arr_aux[i] = d;
      arr[i] = d ? ++count : count;
    }
    int index = 0;
    for(int i = size; i < size + size; i++)
      arr[i] = arr_aux[index++] ? ++count : count;

    int ans[o2], index_of_ans = o2 - 1, index_of_arr = (size + size) - o2 - 1, find = o2 / 2 + 1, aux;
    memset(ans, 0, sizeof(ans));

    for(int i = (size + size)-1; i >= size; i--)
    {
      if(index_of_ans < 0) index_of_ans = o2 - 1;
      ans[index_of_ans--] += (arr[i] - arr[index_of_arr--] >= find) ? 1 : 0;
    }

    aux = ans[0];
    for(int i = 1; i < o2; i++)
      aux = max(aux, ans[i]);

    cout << ((aux >= o1/2 + 1) ? 1 : 0) << endl;

  }

  return 0;
}