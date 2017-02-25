// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=358

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str,aux;
    queue<string> q;
    int counter;
    bool valid;

    while(cin >> str)
    {
        valid = true;
        counter = 0;
        q = queue<string>();
        
        for(int i = 1; i < str.length(); i++)
        {
            if(str[i] <= str[i - 1])
            {
                cout<<counter<<'\n';
                valid = false;
                break;
            }
        }

        if(!valid) continue;

        for(char c = 'a'; c <= 'z'; c++)
        {
            aux = c;
            q.push(aux);
            aux = "";
        }
        
        while(aux != str)
        {
            aux = "";
            aux += q.front();
            char c = aux[aux.length() - 1];
            for(c = c+1 ; c <= 'z'; c++)
                q.push(aux + c);
            q.pop();
            counter++;
 
        }
        cout<<counter<<'\n';
    }

}
