#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>

#define maxSize 1000

using namespace std;

enum {red = 0, orange = 1, yellow = 2, green = 3, blue = 4, violet = 5};

typedef struct color{
  int id;
  int frecuency;
}color;

map<int, char> M;

char ANS[maxSize], ANSL[maxSize];

bool mySort(const color &A, const color &B){ return A.frecuency > B.frecuency; }

void constructLargeSolution(bool single, vector<color> &colors, int n)
{
  int index = 0;
  for(int i = 0; i < n; i++){
    if(ANS[i] == 'R'){
      if(colors[green].frecuency){
        for(int j = 0; j < colors[green].frecuency; j++){
          ANSL[index++] = 'R'; ANSL[index++] = 'G';
        }
        if(!single) ANSL[index++] = 'R';
        colors[green].frecuency = 0;
      }else ANSL[index++] = 'R';
    }
    else if(ANS[i] == 'B'){
      if(colors[orange].frecuency){
        for(int j = 0; j < colors[orange].frecuency; j++){
          ANSL[index++] = 'B'; ANSL[index++] = 'O';
        }
        if(!single) ANSL[index++] = 'B';
        colors[orange].frecuency = 0;
      }else ANSL[index++] = 'B';
    }
    else if(ANS[i] == 'Y'){
      if(colors[violet].frecuency){
        for(int j = 0; j < colors[violet].frecuency; j++){
          ANSL[index++] = 'Y'; ANSL[index++] = 'V';
        }
        if(!single) ANSL[index++] = 'Y';
        colors[violet].frecuency = 0;
      }else ANSL[index++] = 'Y';
    }
  }
}

bool solveSmall(vector<color> &colors, int n)
{
  vector<color> aux = colors;

  sort(aux.begin(), aux.end(), mySort);

  int index = 0, f;
  for(int i = 0; i < 3; i++){
    f = aux[i].frecuency;
    if(f > n/2 && n > 1) return false;
    while(f--){
      if(index >= n) index = 1;
      ANS[index] = M[aux[i].id];
      index += 2;
    }
  }

  return true;
}

bool solveLarge(vector<color> &colors, int n)
{
  vector<color> aux = colors;

  if(aux[blue].frecuency < aux[orange].frecuency ||
     aux[red].frecuency < aux[green].frecuency   ||
     aux[yellow].frecuency < aux[violet].frecuency) return false;

  if(aux[blue].frecuency + aux[orange].frecuency == n){
    if(aux[blue].frecuency != aux[orange].frecuency) return false;
    ANS[red] = 'B';
    constructLargeSolution(true, aux, 1);
    return true;
  }

  if(aux[red].frecuency + aux[green].frecuency == n){
    if(aux[red].frecuency != aux[green].frecuency) return false;
    ANS[red] = 'R';
    constructLargeSolution(true, aux, 1);
    return true;
  }

  if(aux[yellow].frecuency + aux[violet].frecuency == n){
    if(aux[yellow].frecuency != aux[violet].frecuency) return false;
    ANS[red] = 'Y';
    constructLargeSolution(true, aux, 1);
    return true;
  }

  aux[blue].frecuency -= aux[orange].frecuency;
  aux[yellow].frecuency -= aux[violet].frecuency;
  aux[red].frecuency -= aux[green].frecuency;

  if((aux[blue].frecuency <= 0 && aux[orange].frecuency) ||
     (aux[red].frecuency <= 0 && aux[green].frecuency)   ||
     (aux[yellow].frecuency <= 0 && aux[violet].frecuency)) return false;

  aux[orange].frecuency = aux[green].frecuency = aux[violet].frecuency = n = 0;

  for(int i = 0; i < 6; i++)
    n += aux[i].frecuency;

  if(!solveSmall(aux, n)) return false;

  constructLargeSolution(false, colors, n);

  return 1;
}

int main()
{
  int t, f, n;
  M = {{red,'R'}, {yellow,'Y'}, {blue,'B'}};
  scanf("%d",&t);
  for(int test = 1; test <= t; test++){
    scanf("%d",&n);
    vector<color> colors;
    for(int i = 0; i < 6; i++){
      color newColor;
      newColor.id = i;
      scanf("%d",&newColor.frecuency);
      colors.push_back(newColor);
    }
    cout << "Case #" << test << ": ";
    if(!solveLarge(colors, n))
      cout << "IMPOSSIBLE" << '\n';
    else{
      for(int i = 0; i < n; i++)
        cout << ANSL[i];
      cout << '\n';
    }
  }

  return 0;
}