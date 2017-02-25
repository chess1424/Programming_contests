#include <iostream>
#include <vector>
#include <stdio.h>
#define M 1000000007
using namespace std;

//Variables globanles
int i,n;

vector<int> hijos;
vector<vector<int> > tree;
vector<bool> visitados;

int buscarHijos(int v)
{
    int suma=0;

    if(visitados[v]==true)
        return 0;

    visitados[v]=true;

    for(int i=0; i<tree[v].size(); i++)
        suma+=buscarHijos(tree[v][i]);

    hijos[v]=++suma;

    return suma;
}

long long sumaTotal=0, sumaMul, resultado;

void hacerOperacion(int v)
{
    if(visitados[v]==true) return;
    sumaMul=0;
    visitados[v]=true;


    for(int i=0; i<tree[v].size(); i++)
    {
        if(visitados[tree[v][i]]==true) continue;

        for(int j=0; j<tree[v].size(); j++)
        {
            if(visitados[tree[v][j]]==true || i==j) continue;
            sumaMul+=hijos[tree[v][j]]*hijos[tree[v][i]];
        }
    }

    resultado=(long long)(((hijos[v]-1)*2)+sumaMul+1);
    sumaTotal+=(long long)(resultado*v);

    for(int i=0; i<tree[v].size(); i++)
        hacerOperacion(tree[v][i]);

}

int main()
{
    int t,fuente,destino;

    cin>>t;
    while(t--)
    {
        cin>>n;

        tree=vector<vector<int> >(n+1,vector<int>(0));
        hijos=vector<int>(n+1,0);
        visitados=vector<bool>(n+1,false);
        sumaTotal=0;


        for(int i=0; i<n-1; i++)
        {
            cin>>fuente;
            cin>>destino;
            tree[fuente].push_back(destino);
            tree[destino].push_back(fuente);
        }

        buscarHijos(1);

        visitados=vector<bool>(n+1,false);
        hacerOperacion(1);
        sumaTotal=sumaTotal%M;
        cout<<sumaTotal<<endl;

    }

}