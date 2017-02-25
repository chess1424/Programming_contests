// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2315

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

    int t,k,m;
    double arr[256], money, out;
    char key;
    string str;
    cin >> t;
    while(t--)
    {
    	out = 0.00;
    	memset(arr,0,sizeof(arr));
    	cin >> k;
    	for(int i = 0; i < k; i++)
    	{
    		cin >> key >> money;
    		arr[key] = money / 100.00;
    	}
    	cin >> m;
    	cin.ignore();
    	
    	for(int i = 0; i < m; i++)
    	{
    		getline(cin,str);
    		for(int i = 0; i < str.length(); i++)
    			out += arr[str[i]];
    	}
    	printf("%.2lf$\n",out);
    }
	
    return 0;
}
