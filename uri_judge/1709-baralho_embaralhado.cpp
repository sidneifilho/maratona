#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 10000
#define NMAX 105

int main()
{ 

	int p,m,pos1;
	while(scanf("%d", &p) != EOF){
        m = 1;
        pos1 = 2;

        while(pos1 != 1){

            if(pos1 <= p/2)
                pos1 = pos1*2;
            else
                pos1 = pos1*2 - p - 1;

            m++;
        }

        printf("%d\n", m);
	}

   	return 0;
}