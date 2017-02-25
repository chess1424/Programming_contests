// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=880

#include <bits/stdc++.h>
using namespace std;

map< string , pair<string , pair<string , string> > > m;
map< string , pair<string , pair<string , string> > >::iterator it;


string findStatus(string key)
{
	if(m[key].first != "") return m[key].first;
	bool gen = false;
	string padre1, padre2;
	padre1 = m[key].second.first;
        padre2 = m[key].second.second; 

	if(m[padre1].first == "")
		m[padre1].first = findStatus(padre1);
	
	if(m[padre2].first == "")
		m[padre2].first = findStatus(padre2);
	
	if(m[padre1].first == "dominant" || m[padre2].first == "dominant")	
		gen = true;
	
	if(m[padre1].first != "non-existent" && m[padre2].first != "non-existent")
		gen = true;
	
	if(m[padre1].first == "non-existent" && m[padre2].first == "non-existent")
		gen = false;
	
	if(gen)
	{
		if((m[padre1].first == "dominant" && m[padre2].first == "dominant") || (m[padre1].first == "dominant" && m[padre2].first == "recessive") || (m[padre1].first == "recessive" && m[padre2].first == "dominant"))
			return "dominant";
		else
			return "recessive";
	}
	else
		return "non-existent";
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	int t;
	string name, child;
	cin >> t;
	while(t--)
	{
		cin >> name >> child;
		if(child == "non-existent" || child == "recessive" || child == "dominant")
			m[name] = make_pair(child,make_pair("",""));
		else
		{
			it = m.find(child);
			if(it == m.end())
				m[child] = make_pair("",make_pair(name,""));
			else
				it -> second.second.second = name;
		}			
	}

	for(it = m.begin(); it != m.end(); ++it)
	{
		if(it->second.first != "")
			cout<<it->first<<" "<<it->second.first<<'\n';	
		else
			cout<<it->first<<" "<<findStatus(it->first)<<'\n';
	}	
	
	return 0;
}
