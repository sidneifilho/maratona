/// http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/
/// http://marathoncode.blogspot.com.br/2012/04/inverso-multiplicativo.html
/// http://marathoncode.blogspot.com.br/2012/03/aritmetica-do-relogio.html

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define ll long long unsigned int

// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

ll fastexpmod (ll a, ll n, ll m){
  if(n==0) return 1LL;
  else if(n%2==0){
    ll x = fastexpmod(a,n/2LL,m);
    return (x*x)%m; 
  }else
    return (a%m*fastexpmod(a,n-1LL,m))%m;
}

int main (int argc, char* argv[]) {

	ll N,E,C,D,y,msg,teste;
	scanf("%llu %llu %llu", &N, &E, &C);

	ll size = ceil(sqrt(N));

	char prime[size+1];
	memset(prime, 1, sizeof(prime));

	/// gerando os números primos até n usando o crivo de erastotenes
	for (ll p=2; p*p < size; ++p){
		if(prime[p]){
			for (ll i = p*2; i <= size; i+=p)
				prime[i]=0;
		}
	}

	/// verifica qual número primo se N é multiplo do número primo
	for (ll p=3; p <= size; ++p){
		if(prime[p] && N%p==0){

			ll D, y;
			ll phi_n = (p-1)*(N/p - 1); /// calculando o valor de phi_n 

			/// calculando o valor de D
			gcdExtended(E,phi_n,&D,&y);
			D = (D+phi_n)%phi_n; /// inverso modular de E

			/// descripitografando C^D mod n
			msg = fastexpmod(C,D,N);

			printf("%llu\n", msg);
			break;
		}
	}

	return 0;
}
