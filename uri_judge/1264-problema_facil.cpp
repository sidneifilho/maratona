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
    int R[1024], c, resto;
    int i=0, j, base=2;
    while (1) {

        while ((c = getchar()) != '\n' && c != EOF) {

            if (c >= '0' && c <= '9') R[i++] = c - '0';
            else if (c >= 'A' && c <= 'Z') R[i++] = c - 'A' + 10;
            else if (c >= 'a' && c <= 'z') R[i++] = c - 'a' + 36;
            else continue; /* Sinal de -, ignore */

            if (R[i-1] >= base)
                base = R[i-1] + 1;
        }

        if (c == EOF) return 0;

        while (base <= 62) {
            
            resto = 0;
            for (j = 0; j < i; j++) {
                resto = (resto*base + R[j]) % (base-1);
            }

            if (resto == 0)
                break;

            base++;
        }

        if (base == 63)
            printf("such number is impossible!\n");
        else
            printf("%d\n", base);

        i=0; base = 2;
    }
}