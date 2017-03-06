#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define maxSize 1005
#define notVisited -1

using namespace std;

int visited[maxSize];

bool bfs(const int node, const vector<int> (&nodes)[maxSize])
{
  queue<int> q; q.push(node);
  visited[node] = 1;
  int group;

  while(!q.empty())
  {
    int node = q.front(); q.pop();
    group = visited[node] ? 0 : 1;

    for(auto child : nodes[node])
    {
      if(visited[child] == notVisited)
      {
        visited[child] = group;
        q.push(child);
      }
      else
      {
        if(visited[child] != group)
          return false;
      }
    }
  }

  return true;
}

int main()
{
  int n, m, u, v;
  memset(visited, notVisited, sizeof visited);
  scanf("%d %d",&n,&m);

  vector<int> nodes[maxSize];

  for(int i = 0; i < m; i++)
  {
    scanf("%d %d",&u, &v);
    nodes[--u].push_back(--v);
    nodes[v].push_back(u);
  }

  bool ans = true;
  for(int i = 0; i < n && ans; i++)
  {
    if(visited[i] == notVisited)
      ans = bfs(i, nodes);
  }

  puts(ans ? "YES" : "NO");

  return 0;
}