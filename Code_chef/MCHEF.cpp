#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <string.h>
#define infinity 100009
using namespace std;
typedef struct judge{
    long long l;
    long long r;
    long long c;
}judge;


vector<long long> mins;
vector<long long> a;
long long K[501];

long long knapSack(long long n, long long W)
{
    memset(K,0,sizeof(K));
    for(long long i=0; i<=n; i++)
    {
        for(long long j=W; j>=0; j--)
        {
            K[j] = (mins[i] > j) ? K[j] : min(K[j] , K[j - mins[i]] + a[i]);
        }
    }
    return K[W];
}

int main()
{
    long long t,n,k,m,i,j,l,r,c,left,right,operindex,cost,totalRating;

    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
        vector<judge> judges(m+1);
        a = vector<long long>(n+1);
        mins = vector<long long>(n+1,infinity);
        vector<long long> L[n+1];
        vector<long long> R[n+1];

        totalRating=0;


        for(i=1; i<=n; i++)
        {
            cin>>a[i];
            totalRating+=a[i];
        }


        for(i=1; i<=m; i++)
        {
            judge newJudge;
            cin>>l>>r>>c;
            newJudge.l=l;
            newJudge.r=r;
            newJudge.c=c;
            judges[i]=newJudge;
        }

        set<pair<int,int>> iset;

        for(i=1; i<=m; i++)
        {
            left=judges[i].l;
            right=judges[i].r;

            L[left].push_back(i);
            R[right].push_back(i);
        }

        for(i=1; i<=n; i++)
        {
            for(j=0; j<L[i].size(); j++)
            {
                operindex=L[i][j];
                cost=judges[operindex].c;

                iset.insert(make_pair(cost,operindex));

            }

            mins[i] = ((iset.begin()->first)>0)?iset.begin()->first:infinity;

            for(j=0; j<R[i].size(); j++)
            {
                operindex=R[i][j];
                cost=judges[operindex].c;

                iset.erase(make_pair(cost,operindex));

            }


        }

        cout<<knapSack(n,k)*-1+totalRating<<endl;
    }
    return 0;
}