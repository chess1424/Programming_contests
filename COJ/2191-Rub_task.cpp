#include <iostream>
#include <queue>
#include <string.h>

#define maxSize 100

using namespace std;

typedef struct node{
  int i;
  int j;
  long long value;

  friend bool operator<(const node& a, const node& b)
  {
    return a.value > b.value;
  }
}node;

bool visited[maxSize][maxSize];
node arr[maxSize][maxSize];

bool isValidNodeToAdd(int i, int j, int rows, int cols)
{
  return i >= 0 && i < rows && j >= 0 && j < cols && !visited[i][j];
}

bool isRightEdge(int j, int cols)
{
  return j == cols - 1;
}

long long solve(priority_queue<node> pq, int rows, int cols)
{
  while(!pq.empty())
  {
    node n = pq.top();
    int i = n.i;
    int j = n.j;

    if(isRightEdge(j, cols)) return n.value;

    //check for up node
    if(isValidNodeToAdd(i-1, j, rows, cols))
    {
      node nodeToAdd = arr[i-1][j];
      visited[i-1][j] = true;
      nodeToAdd.value += n.value;
      pq.push(nodeToAdd);
    }
    //Check for bottom node
    if(isValidNodeToAdd(i+1, j, rows, cols))
    {
      node nodeToAdd = arr[i+1][j];
      visited[i+1][j] = true;
      nodeToAdd.value += n.value;
      pq.push(nodeToAdd);
    }
    //Check for right node
    if(isValidNodeToAdd(i, j+1, rows, cols))
    {
      node nodeToAdd = arr[i][j+1];
      visited[i][j+1] = true;
      nodeToAdd.value += n.value;
      pq.push(nodeToAdd);
    }
    //Check for left node
    if(isValidNodeToAdd(i, j-1, rows, cols))
    {
      node nodeToAdd = arr[i][j-1];
      visited[i][j-1] = true;
      nodeToAdd.value += n.value;
      pq.push(nodeToAdd);
    }

    pq.pop();
  }

  return -1;
}

int main()
{
  int n, m;

  while(scanf("%d %d",&n,&m) != EOF)
  {
    priority_queue<node> pq;
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
      {
        node n;
        n.i = i;
        n.j = j;
        scanf("%lld",&n.value);
        arr[i][j] = n;
      }

    for(int i = 0; i < n; i++)
    {
      pq.push(arr[i][0]);
      visited[i][0] = true;
    }

    cout << solve(pq, n, m) << endl;
  }
  return 0;
}