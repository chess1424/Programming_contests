#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

typedef struct element{
    int i;
    int j;
}element;

element arr[250001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,index;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                cin>>index;
                element newElement;
                newElement.i = i;
                newElement.j = j;
                arr[index] = newElement;
            }

        long long out = 0;
        for(int i=1; i<n*n; i++)
          out +=  abs(arr[i].i - arr[i+1].i) + abs(arr[i].j - arr[i+1].j);

        cout<<out<<endl;
    }
    return 0;
}