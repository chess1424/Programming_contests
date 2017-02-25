#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char,char> m;
string buildMirror(string str) //Construimos el espejo del string original
{
	string mirror = "";
	for(int i = 0; i < str.size(); i++)
		if(m[str[i]]) mirror+= m[str[i]];
	return mirror;
}

bool isPalindrome(string str)//Revisamos si es un palindrome
{
	int left = 0, right = str.size() - 1;; 
	while(left <= right)
		if(str[left++] != str[right--]) return false;
	return true;
}

bool isMirrored(string str, string str2) //Revisamos si es un espejo
{
	if(str.size() != str2.size()) return false;

	int firstStr = 0, lastStr2 = str2.size()-1;
	while(firstStr != str.size())
		if(str[firstStr++] != str2[lastStr2--]) return false;
	return true;
}


int main()
{
	string str;
	m['A'] = 'A';
	m['E'] = '3';
	m['H'] = 'H';
	m['I'] = 'I';
	m['J'] = 'L';
	m['L'] = 'J';
	m['M'] = 'M';
	m['O'] = 'O';
	m['S'] = '2';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['1'] = '1';
	m['2'] = 'S';
	m['3'] = 'E';
	m['5'] = 'Z';
	m['8'] = '8';



	while(cin>>str)
	{
		string mirror = buildMirror(str);


		if(!isPalindrome(str) && !isMirrored(str,mirror))
			cout<<str<<" -- is not a palindrome."<<'\n';
		else if(isPalindrome(str) && !isMirrored(str,mirror))
			cout<<str<<" -- is a regular palindrome."<<'\n';
		else if(!isPalindrome(str) && isMirrored(str,mirror))
			cout<<str<<" -- is a mirrored string."<<'\n';
		else cout<<str<<" -- is a mirrored palindrome."<<'\n';
		cout<<endl;
	}
	return 0;
}