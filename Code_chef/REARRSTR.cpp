#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool mysort(tuple<char,int> lcounting, tuple<char,int> rcounting)
{
    return get<1>(lcounting) > get<1>(rcounting);
}
int main()
{
    long long t,len,i;
    cin>>t;
    string str;

    while(t--)
    {
        cin>>str;
        len=str.size();

        tuple<char,int> counting[27];
        for(i=0; i<len; i++)
        {
            char c=str[i];
            get<0>(counting[c-'a'])=c;
            get<1>(counting[c-'a'])++;
        }

        sort(counting,counting+27,mysort);//Sorting as decreasing way.
        if(get<1>(counting[0])>(len+1)/2){cout<<-1<<endl; continue;}


        char currChar=get<0>(counting[0]);
        cout<<currChar;
        get<1>(counting[0])--;
        sort(counting,counting+27,mysort);

        while(get<1>(counting[0])>0)
        {
            if(get<0>(counting[0])!=currChar)
            {
                currChar=get<0>(counting[0]);
                cout<<currChar;
                get<1>(counting[0])--;
            }
            else
            {
                currChar=get<0>(counting[1]);
                cout<<currChar;
                get<1>(counting[1])--;
            }

             sort(counting,counting+27,mysort);
        }

        cout<<endl;


    }
    return 0;
}