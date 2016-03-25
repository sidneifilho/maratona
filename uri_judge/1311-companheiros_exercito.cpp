#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define ll long long unsigned int
#define MOD 1000000007

#define NMAX 100005

int main (int argc, char* argv[]) {

	int l[NMAX], r[NMAX];
	int B,S,sl,sr;
	while(scanf("%d %d", &S, &B) != EOF && B != 0 && S != 0){

		for (int i = 1; i <= S; ++i)
			l[i] = i-1, r[i] = i+1;

		for (int i = 0; i < B; ++i)
		{
			scanf("%d %d", &sl, &sr);

			if(l[sl] > 0) printf("%d ", l[sl]);
			else printf("* ");

			if(r[sr] <= S) printf("%d", r[sr]);
			else printf("*");

			l[r[sr]] = l[sl];
			r[l[sl]] = r[sr];

			printf("\n");
		}

		printf("-\n");
	}

    return 0;
}