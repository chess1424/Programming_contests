/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@@live.com.mx>
   Problem_statement: https://uva.onlinejudge.org/external/112/11235.pdf
   Topic: Segment Tree */

#include <iostream>
#include <climits>

#define maxSize 200006

using namespace std;

int input[maxSize], boundaryRight[maxSize], boundaryLeft[maxSize],
    segmentTree[maxSize*2], n;

int maxFrequency(int qlow, int qhigh, int low, int high, int pos)
{
  int partialLeft = 0, partialRight = 0;

  //total overlap
  if(qlow <= low && qhigh >= high)
    return segmentTree[pos];

  //no overlap
  if(qlow > high || qhigh < low)
    return INT_MIN;

  //partial overlap
  if(qlow-1 >= 0 && input[qlow] == input[qlow-1])
  {
    if(boundaryRight[qlow] >= qhigh) return qhigh - qlow + 1;

    partialLeft = boundaryRight[qlow] - qlow + 1;
    qlow = boundaryRight[qlow] + 1;
  }
  if(qhigh + 1 <= n-1 && input[qhigh] == input[qhigh+1])
  {
    partialRight = qhigh - boundaryLeft[qhigh] + 1;
    qhigh = boundaryLeft[qhigh] - 1;
  }

  int mid   = (low + high)/2;
  int left  = maxFrequency(qlow, qhigh, low, mid, 2*pos+1);
  int right = maxFrequency(qlow, qhigh, mid+1, high, 2*pos+2);

  return max(max(max(left, right), partialRight) , partialLeft);
}

void constructTree(int low, int high, int pos)
{
  if(low == high)
  {
    segmentTree[pos] = input[low];
    return;
  }

  int mid = (low + high)/2;
  constructTree(low, mid, 2*pos+1);
  constructTree(mid+1, high, 2*pos+2);
  segmentTree[pos] = max(segmentTree[2*pos+1], segmentTree[2*pos+2]);
}

int main()
{
  int q, qlow, qhigh;

  while(cin >> n >> q && n)
  {
    int currNum, prevNum, frequency = 1, i = 0;

    cin >> prevNum;

    for(int j = 1; j < n; j++)
    {
      cin >> currNum;

      if(currNum == prevNum)
        frequency++;
      else
      {
        fill(input + i, input + j, frequency);
        fill(boundaryRight + i, boundaryRight + j, j-1);
        fill(boundaryLeft + i, boundaryLeft + j, i);
        prevNum = currNum;
        frequency = 1;
        i = j;
      }
    }fill(input + i, input + n, frequency);
     fill(boundaryRight + i, boundaryRight + n, n-1);
     fill(boundaryLeft + i, boundaryLeft + n, i);

    constructTree(0, n-1, 0);

    for(int i = 0; i < q; i++)
    {
      int low, high;
      cin >> low >> high;
      cout << maxFrequency(low-1, high-1, 0, n-1, 0) << endl;
    }
  }

  return 0;
}

