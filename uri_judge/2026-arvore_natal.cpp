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

int knapsack(){

	int K[P+1][W+1];

	for (int i = 0; i <= P; ++i)
	{
		for (int w = 0; w <= W; ++w)
		{
			if(i == 0 || w == 0)
				K[i][w] = 0;
			else if(wt[i-1] <= w) 
				K[i][w] = max(vt[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}

	return K[P][W];
}

int main(int argc, char *argv[])
{

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		//if(i!=0) printf("\n");

		scanf("%d", &P);
		scanf("%d", &W);

		for (int j = 0; j < P; ++j)
		{
			scanf("%d %d", &vt[j], &wt[j]);
		}

		int res = knapsack();
		printf("Galho %d:\n", i+1);
		printf("Numero total de enfeites: %d\n\n", res);
	}

	return 0;
}