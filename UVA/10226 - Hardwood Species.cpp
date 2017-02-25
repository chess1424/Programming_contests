// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1167

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int t;
    double count;

    cin >> t;
    cin.ignore();
    getline(cin,str);
    for(int i = 0; i < t; i++)
    {
    	if(i != 0) printf("\n");
    	map<string,int> m;
    	count = 0.00;
    	while(getline(cin,str))
    	{
    		if(str == "") break;
    		m[str]++;
    		count++;
    	}

    	map<string,int>::iterator it;
    	for(it = m.begin(); it != m.end(); ++it)	
    		printf("%s %.4f\n",(it->first).c_str(),(m[it->first]*100) / count); 
    }
    return 0;
}
