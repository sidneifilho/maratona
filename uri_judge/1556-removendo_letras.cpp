/// gerando número de possíveis palavras - backtracking
#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 1000000007
 
#define NMAX 100005

set<string> possiveis;
set<string>::iterator it;
unsigned tam;
string s, s1;
 
void backtracking(unsigned i)
{  
	if(!possiveis.count(s1)) 
	{ 
		if(i==tam) { 
			if(s1.length()){  
				possiveis.insert(s1);
			}
		}else{ 
			s1.push_back(s[i]);
			backtracking(i+1);
			s1.erase(s1.end()-1);
			backtracking(i+1);
		}
	}
}
 
int main()
{ 
	while(cin >> s)
	{ 
		tam = s.length();
		backtracking(0);

		for(it=possiveis.begin(); it!=possiveis.end(); it++)
			printf("%s\n",it->c_str());
		printf("\n");

		possiveis.clear();
		s1.clear();
	}
   return 0;
}