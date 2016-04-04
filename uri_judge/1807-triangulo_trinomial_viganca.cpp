/// fast exponation with mod
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 2147483647 // pow(2,31)-1
#define INF 999999999
#define VMAX 15

#define rep(i,N) for(int i=0;i<N;i++)

ll fastexp(ll a, ll b){

	ll x;

	if(b==0) return 1;
	if(b==1) return a;

	if(b%2==0){
		x = fastexp(a,b/2)%MOD;
		return (x*x)%MOD;
	}else{
		return (a*fastexp(a,b-1))%MOD;
	}
}

int main(int argc, char const *argv[])
{
	//ios_base::sync_with_stdio(false); 
	//cin.tie(NULL); 

	ll n;
	scanf("%llu", &n);

	printf("%llu\n", fastexp(3,n));

	return 0;
}