/// trocar os elementos dentro do ciclo apenas
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 2147483647 // pow(2,31)-1
#define INF 999999999
#define NMAX 28005

#define rep(i,N) for(int i=0;i<N;i++)

int main(void) {
    int T, N, S[10001], B[10001], j, k, soma;
    scanf("%d", &T);
    while (T-- > 0) {
        soma = 0;
        scanf("%d", &N);
        for (j = 1; j <= N; j++) {
            scanf("%d", &S[j]);
            B[j] = 1;
        }
        for (j = 1; j <= N; j++) {
            if (B[j]) {
                for (k = j; S[k] != j; k = S[k]) {
                    B[k] = 0;
                    soma++;
                }
                B[k] = 0;
            }
        }
        printf("%d\n", soma);
    }
    return 0;
}