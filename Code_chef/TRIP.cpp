#include<bits/stdc++.h>
#define M 1000000007
typedef long long ll;
using namespace std;
ll dist[1000010],ways[1000010],a[1000010];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,m,i,j=0,k=0,sum=0;
  cin>>n>>m;
  for(i=0;i<n;i++)
    cin>>a[i];
  ways[0]=1;
  for(i=1;i<n;i++)
  {
    while(a[i]-a[j]>m)
      sum-=(ll)(ways[j++]);
    dist[i]=dist[j]+1;
    while(dist[k]==dist[j])
      sum+=(ll)(ways[k++]);
    ways[i]=sum%M;
  }
  cout<<dist[n-1]-1<<' '<<ways[n-1]<<'\n';
  return 0;
}