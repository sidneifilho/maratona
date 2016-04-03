/// calculo da area do triangulo em função das medianas
#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 1000000007
#define INF 999999999
#define VMAX 255

#define rep(i,N) for(int i=0;i<N;i++)

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	double m1,m2,m3, area,sm,fator;
	int qt_neg;
	while(scanf("%lf %lf %lf", &m1, &m2, &m3) != EOF ){

		sm = (m1+m2+m3)/2.0;
		fator = sm*(sm-m1)*(sm-m2)*(sm-m3);

		area = -1.0;
		if(fator > 0.0)
			area = (4.0/3.0) * sqrt(fator);

		printf("%.3lf\n", area);
	}

	return 0;
}