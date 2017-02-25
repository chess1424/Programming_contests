#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long n,m,espacios,out,min;
    vector<long long> arr(20000,-1);
    cin>>t;
    while(t--)
    {
        out = 0;
        cin>>n>>m;
        for(long long i=0; i<m; i++)
        {
            cin>>arr[i];
        }
        espacios = m - 1;
        sort(arr.begin(), arr.begin() + m);
        min = arr[0];

        if(min >= espacios)
        {
            out = espacios;
        }
        else
        {
            long long index = 0;
            while(espacios != 0)
            {
                if(arr[index] < espacios)
                {
                    espacios -= arr[index];
                    out += arr[index];
                    espacios -= 1;
                    index++;
                }
                else if(arr[index] == espacios)
                {
                    out += arr[index];
                    espacios = 0;
                }
                else
                {
                    out += espacios;
                    espacios = 0;
                }
            }
        }
        cout<<out<<endl;
    }
    return 0;
}