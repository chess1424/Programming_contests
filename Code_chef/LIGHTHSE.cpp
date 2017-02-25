#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct point{
    long long x;
    long long y;
    long long id;
}point;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    point topL, topR;
    point bottomL, bottomR;
    point leftU, leftL;
    point rightU, rightL;
    long long n,minX,maxX,minY,maxY,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>x>>y;
        maxX = minX = x;
        maxY = minY = y;

        topL.x = x;
        topL.y = y;
        topL.id = 1;
        topR.x = x;
        topR.y = y;
        topR.id = 1;

        bottomL.x = x;
        bottomL.y = y;
        bottomL.id = 1;
        bottomR.x = x;
        bottomR.y = y;
        bottomR.id = 1;

        leftU.x = x;
        leftU.y = y;
        leftU.id = 1;
        leftL.x = x;
        leftL.y = y;
        leftL.id = 1;

        rightU.x = x;
        rightU.y = y;
        rightU.id = 1;
        rightL.x = x;
        rightL.y = y;
        rightL.id = 1;


        for(long long i=2; i<=n; i++)
        {
            cin>>x>>y;

            //Obteniendo los puntos extremos de la izquierda*
            if(x < minX)
            {
                minX = x;
                leftL.x = x;
                leftL.y = y;
                leftL.id = i;

                leftU.x = x;
                leftU.y = y;
                leftU.id = i;
            }
            if(x == minX)
            {
                if(y > leftU.y)
                {
                    leftU.y = y;
                    leftU.id = i;
                }
                if(y < leftL.y)
                {
                    leftL.y = y;
                    leftL.id = i;
                }
            }

            //Obteniendo los puntos extremos de la derecha
            if(x > maxX)
            {
                maxX = x;

                rightL.x = x;
                rightL.y = y;
                rightL.id = i;

                rightU.x = x;
                rightU.y = y;
                rightU.id = i;
            }
            if(x == maxX)
            {
                if(y > rightU.y)
                {
                    rightU.y = y;
                    rightU.id = i;
                }
                if(y < rightL.y)
                {
                    rightL.y = y;
                    rightL.id =i;
                }
            }

            //Obteniendo los puntos extremos de abajo
            if(y < minY)
            {
                minY = y;

                bottomL.x = x;
                bottomL.y = y;
                bottomL.id = i;

                bottomR.x = x;
                bottomR.y = y;
                bottomR.id = i;

            }
            if(y == minY)
            {
                if(x > bottomR.x)
                {
                    bottomR.x = x;
                    bottomR.id = i;
                }
                if(x < bottomL.x)
                {
                    bottomL.x = x;
                    bottomL.id =i;
                }

            }

            //Obteniendo los puntos extremos de arriba
            if(y >= maxY)
            {
                maxY = y;

                topL.x = x;
                topL.y = y;
                topL.id = i;

                topR.x = x;
                topR.y = y;
                topR.id = i;
            }
            if(y == maxY)
            {
                if(x < topL.x)
                {
                    topL.x = x;
                    topL.id = i;
                }
                if(x > topR.x)
                {
                    topR.x = x;
                    topR.id = i;
                }
            }
        }

        //Verificando top
        if(topL.x == minX)
        {
            cout<<1<<endl;
            cout<<topL.id<<" SE"<<endl;
        }
        else if(topR.x == maxX)
        {
            cout<<1<<endl;
            cout<<topR.id<<" SW"<<endl;
        }

        //Verificando right
        else if(rightU.y == maxY)
        {
            cout<<1<<endl;
            cout<<rightU.id<<" SW"<<endl;
        }
        else if(rightL.y == minY)
        {
            cout<<1<<endl;
            cout<<rightL.id<<" NW"<<endl;
        }

        //Verificando bottom*
        else if(bottomL.x == minX)
        {
            cout<<1<<endl;
            cout<<bottomL.id<<" NE"<<endl;
        }
        else if(bottomR.x == maxX)
        {
            cout<<1<<endl;
            cout<<bottomR.id<<" NW"<<endl;
        }

        //Verificando left
        else if(leftL.y == minY)
        {
            cout<<1<<endl;
            cout<<leftL.id<<" NE"<<endl;
        }
        else if(leftU.y == maxY)
        {
            cout<<1<<endl;
            cout<<leftU.id<<" SE"<<endl;
        }

        else
        {
            cout<<2<<endl;
            if(rightL.y >= leftL.y)
            {
                cout<<leftL.id<<" NE"<<endl;
                cout<<rightL.id<<" SW"<<endl;
            }
            else
            {
                cout<<leftL.id<<" SE"<<endl;
                cout<<rightL.id<<" NW"<<endl;
            }


        }
    }
    return 0;
}