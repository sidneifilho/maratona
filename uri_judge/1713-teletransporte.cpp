/// exponenciação de matrizes e principio de markov para identificar o número de possibilidades
/// de alcancar j a partir de i dado m passos
#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 10000
#define NMAX 105

int N;
 
/* Funções auxiliares de "power". */ 
void one (ll a[NMAX][NMAX] ) {
    int i, j;
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= N; j++ )
            a[i][j] = ( i == j );
}
 
void mul (ll a[NMAX][NMAX], ll b[NMAX][NMAX] ) {
    ll res[NMAX][NMAX] = {{0}};
    int i, j, k;
 
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= N; j++ )
            for ( k = 1; k <= N; k++ ) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
 
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= N; j++ )
            a[i][j] = res[i][j];
}
 
/* Eleva a matriz "a" por "n", guarda o resultado em "res". */
void power (ll a[NMAX][NMAX], ll n, ll res[NMAX][NMAX] ) {
    one ( res );
 
    while ( n > 0 ) {
        if ( n % 2 == 0 ) {
            mul ( a, a );
            n /= 2;
        }else {
            mul ( res, a );
            n--;
        }
    }
}

int main()
{ 
	ll A[NMAX][NMAX], B[NMAX][NMAX];
	ll m;

	int a, b, c, d, S,E,i,j;
	while(cin >> N >> m){
		cin >> S >> E;

		/// setando os valores possiveis de ir de cada nave para cada nave
		memset(A, 0, sizeof(A));
		for (i = 1; i <= N; ++i)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			A[i][a]++; A[i][b]++; A[i][c]++; A[i][d]++; 
		}

		/// analisando as possibilidade existentes dado m passos
		power(A, m, B);

		printf("%llu\n", B[S][E]%MOD);
	}

   	return 0;
}