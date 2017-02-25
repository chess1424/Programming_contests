#include <iostream>
#include <algorithm>
#define INF 2000000000.0
using namespace std;

typedef struct team{
  string name[5];
  long double kda[5];
}team;

int main()
{
  long double lowest_lost, half_lost = 0.5, third_win = 0.33, kills, deaths;
                       
  int t;
  scanf("%d",&t);
  while(t--)
  {
    lowest_lost = INF;
    team winner;
    team lost;
    for(int i = 0; i < 5; i++)
    {
      cin >> winner.name[i];
      scanf("%Lf %Lf",&kills,&deaths);
      if(deaths == 0)
        winner.kda[i] = INF;
      else
        winner.kda[i] = kills / deaths;
    }

    for(int i = 0; i < 5; i++)
    {
      cin >> lost.name[i];
      scanf("%Lf %Lf",&kills,&deaths);
      if(deaths == 0)
        lost.kda[i] = INF;
      else
        lost.kda[i] = kills / deaths;
      lowest_lost = min(lowest_lost, lost.kda[i]);
    }
  
    for(int i = 0; i < 5; i++)
      if(winner.kda[i] < third_win)
        cout << winner.name[i] << " plz uninstall" << "\n";    
    
    for(int i = 0; i < 5; i++)
    {
      long double kda = lost.kda[i]; 
      if(kda == lowest_lost || kda < half_lost)
        cout << lost.name[i] << " plz uninstall" << "\n";
    }

  }
  return 0;
}


  

