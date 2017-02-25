#include <iostream>
#include <stdio.h>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


typedef struct rect{
    long uperLeftX;
    long dentro;
    long id;
}rect;


bool mysort(rect n, rect d){return n.uperLeftX>d.uperLeftX;}
bool mysort2(rect n, rect d){return n.id<d.id;}
int main()
{
    ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    long t,n,m,i,j,num;
    rect currRect;
    vector<rect> rectangulos;

    cin>>t;

    while(t--)
    {
        rectangulos.clear();
        cin>>n;
        for(j=0; j<n; j++)
        {
            cin>>m;
            cin>>currRect.uperLeftX;
            cin>>num;
            m=(m*2)-2;

            for(i=0; i<m; i++)
            {
                cin>>num;
                if(i%2==0)
                    if(num<currRect.uperLeftX) currRect.uperLeftX=num;
            }
            currRect.id=j;
            rectangulos.push_back(currRect);
        }

        sort(rectangulos.begin(), rectangulos.end(), mysort);
        for(i=0; i<rectangulos.size(); i++)
            rectangulos[i].dentro=i;
        sort(rectangulos.begin(), rectangulos.end(), mysort2);
        for(i=0; i<rectangulos.size(); i++)
            cout<<rectangulos[i].dentro<<" ";

        cout<<endl;

    }
    return 0;
}