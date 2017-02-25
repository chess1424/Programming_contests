// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2619

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long t,n,num,out,left;
    scanf("%lld",&t);
    while(t--)
    {
        out = 0; 
        map<long long, long long> m;
        scanf("%lld",&n);
        left = 1;
        for(long long i = 1; i <= n; i++)
        {
            scanf("%lld",&num);

            if(!m[num] || m[num] < left)
            {
                m[num] = i;
                if(i == n) out = max(out, n - left + 1);
            }
            else
            {
                out = max(out , i - left);
                left = m[num] + 1;
                m[num] = i;
            }
        }
        printf("%lld\n",out);
    }
    return 0;
}   
