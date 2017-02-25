//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3456&cid=1479

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string str,str2,s,s2;
    cin >> t;
    bool yes;
    cin.ignore();
    while(t--)
    {
        getline(cin,str);
        getline(cin,str2);
        map<char,int> m;
        yes = true;

        s = "";
        s2 = "";
        for(int i = 0; i < str.length(); i++)
            if(str[i] != ' ') s += str[i];
        for(int i = 0; i < str2.length(); i++)
            if(str2[i] != ' ') s2 += str2[i];

        if(s.length() != s2.length())
        {
            cout<<"no"<<'\n';
            continue;
        }

        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
            
        for(int i  = 0; i < s2.length(); i++)
        {
            if(!m[s2[i]]) yes = false;
            else
            {
                if(m[s2[i]] <= 0) yes = false;
                m[s2[i]]--;
            }
        }

        if(yes) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';

    }    
}
