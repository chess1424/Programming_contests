//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3430&cid=1479

#include <bits/stdc++.h>
using namespace std;

string reverse(string str)
{
    int l,r;
    l = 0;
    r = str.length()-1;
    while(l <= r)
    {
        char aux = str[l];
        str[l++] = str[r];
        str[r--] = aux;
    }
    return str;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, out, rev;
    stack<int> s;
    while(getline(cin,str))
    {
        out = "";
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '(')
                s.push(i+1);
            else if(str[i] == ')')
            {
                int index = s.top();
                rev = reverse(str.substr(index,i-s.top()));
                for(int j =  0; j < rev.length(); j++)
                    str[index++] = rev[j];
                s.pop();
            }
        }
        for(int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if(c != '(' && c != ')')
                out += c;
        }
        cout<<out<<'\n';
    }
}
