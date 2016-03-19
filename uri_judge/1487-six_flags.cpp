/// programação dinamica - knapsack
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < n; ++i)
#define NMAX 250005
#define ii pair<int, int >

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

int P, W;
int vt[105], wt[105];

int knapsack()  
{  
	int tmp;  

	int M[W+1];
	M[0] = 0;  
	for(int w=1; w <= W; w++)  
	{  
		M[w] = M[w-1];              
		for(int j=0; j < P; j++)  
		{  
			if (wt[j] <= w)  
				tmp = M[w-wt[j]] + vt[j];

			if (tmp > M[w]) M[w] = tmp;
		}    
	}   

	return M[W];  
}  

int main(int argc, char *argv[])
{

	int cnt = 0;
	while(cin >> P >> W && P != 0 && W != 0){

		for (int i = 0; i < P; ++i)
		{
			cin >> wt[i] >> vt[i];
		}

		int res = knapsack();
		printf("Instancia %d\n", ++cnt);
		printf("%d\n\n", res);
	}

	return 0;
}