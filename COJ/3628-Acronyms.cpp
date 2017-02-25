#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str1, str2;
  
  while(getline(cin , str1))
  {
  	vector<char> v1, v2;
  	v1.push_back(str1[0]);
  	for(int i = 0; i < str1.length(); i++)
  		if(str1[i] == ' ')
  			v1.push_back(str1[i + 1]);
 	 	
 	 	getline(cin, str2);
 	 	v2.push_back(str2[0]);
 	 	for(int i = 0; i < str2.length(); i++)
 	 		if(str2[i] == ' ')
 	 			v2.push_back(str2[i + 1]);

 	 	if(v1.size() != v2.size())
 	 		printf("no\n");
 	 	else
 	 	{
 	 		bool equal = true;
 	 		for(int i = 0; i < v1.size(); i++)
 	 			if(v1[i] != v2[i]){ equal  = !equal;  break;} 
 	 		
 	 		if(equal)
 	 			printf("yes\n");
 	 		else
 	 			printf("no\n");

 	 	}
  }

  return 0;
}
