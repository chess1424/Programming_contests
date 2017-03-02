#include <iostream>
#include <climits>
#include <queue>
#include <string>

#define maxSize 1000

using namespace std;

char arr[maxSize][maxSize];

void bfs(queue< pair<int , int > > q, int r, int c, int path[maxSize][maxSize])
{
  int rows[] = { -1, 0, 1, 0};//up right down left
  int cols[] = { 0, 1, 0, -1};

  while(!q.empty())
  {
    int currRow, currCol;
    currRow = q.front().first;
    currCol = q.front().second;

    for(int i = 0; i < 4; i++)
    {
      if(currRow + rows[i] >= 0 && currRow + rows[i] < r &&
        currCol + cols[i] >= 0 && currCol + cols[i] < c &&
        arr[currRow + rows[i]][currCol + cols[i]] != '#' &&
        path[currRow + rows[i]][currCol + cols[i]] > path[currRow][currCol] + 1){

          path[currRow + rows[i]][currCol + cols[i]] = path[currRow][currCol] + 1;
          q.push(make_pair(currRow + rows[i], currCol + cols[i]));
      }
    }
    q.pop();
  }
}

int main()
{
  int r, c, jonPath[maxSize][maxSize], firePath[maxSize][maxSize];
  int cont = 0;
  while(scanf("%d %d",&r, &c) != EOF)
  {
    queue< pair<int , int> > jonQ;
    queue< pair<int , int> > fireQ;
    getchar();
    for(int i = 0; i < r; i++)
    {
      fill(jonPath[i], jonPath[i] + c, INT_MAX);
      fill(firePath[i], firePath[i] + c, INT_MAX);
      for(int j = 0; j < c; j++)
      {
        arr[i][j] = getchar();

        if(arr[i][j] == 'J')
        {
          jonQ.push(make_pair(i,j));
          jonPath[i][j] = 0;
        }
        if(arr[i][j] == 'F')
        {
          fireQ.push(make_pair(i,j));
          firePath[i][j] = 0;
        }
      }
      getchar();
    }

    bfs(jonQ, r, c, jonPath);
    bfs(fireQ, r, c, firePath);

    //Check horizontal edges
    int ans = INT_MAX;
    for(int i = 0; i < c; i++)
    {
      if(jonPath[0][i] < firePath[0][i]) ans = min(ans , jonPath[0][i]);
      if(jonPath[r-1][i] < firePath[r-1][i]) ans = min(ans, jonPath[r-1][i]);
    }

    //Check vertical edges
    for(int i = 0; i < r; i++)
    {
      if(jonPath[i][0] < firePath[i][0]) ans = min(ans , jonPath[i][0]);
      if(jonPath[i][c-1] < firePath[i][c-1]) ans = min(ans, jonPath[i][c-1]);
    }

    if(ans != INT_MAX)
      cout << ans + 1 << endl;
    else
      cout << "IMPOSSIBLE" << endl;

  }
  return 0;
}