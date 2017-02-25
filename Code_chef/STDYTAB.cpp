
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;
int rows,columns;
vector<vector<long long> >conbinations(2001,vector<long long>(2001,-1));
vector<vector<long long> >ans;
long long conbination(int n, int r)
{
    if( n == 0 ) return r == 0 ? 1 : 0;
    if( r < 0 ) return 0;
    if( conbinations[n][r] != -1) return conbinations[n][r];
    return conbinations[n][r] = (conbination( n - 1, r) + conbination( n, r - 1)) % MOD;
}
long long solve(int n, int m)
{
    if(ans[n][m]!=-1)return ans[n][m];
    if(m>columns) return 0;
    if(n==rows+1) return 1;
    return ans[n][m]=((solve(n+1,m)*conbination(columns,m))+(solve(n,m+1)))%MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>rows>>columns;
        ans=vector<vector<long long> >(rows+2,vector<long long>(columns+2,-1));
        cout<<solve(1,0)<<endl;
    }
    return 0;
}