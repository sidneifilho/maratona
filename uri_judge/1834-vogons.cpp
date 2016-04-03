/// ponto, reta, distancia entres pontos
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 1000000007
#define INF 999999999
#define VMAX 255

#define rep(i,N) for(int i=0;i<N;i++)

struct Ponto{
	ld x, y;
	ll h;

	Ponto():x(0.0),y(0.0),h(0){}

	Ponto(ld _x, ld _y, ll _h):x(_x),y(_y),h(_h){}
};

struct Reta{
	ld a, b, c;

	Reta(const Ponto& pa, const Ponto& pb){
		a = pa.y - pb.y;
		b = pb.x - pa.x;
		c = pa.x*pb.y - pa.y*pb.x;
	}

	/// negative is one side, positive is other side,
	/// 0 indicates that the point is under the line
	int side(const Ponto& p){
		return (a*p.x + b*p.y + c);
	}
};

ld dist(const Ponto& p, const Reta& r){
	return fabs(r.a*p.x + r.b*p.y + r.c)/sqrt(r.a*r.a + r.b*r.b);
}

/// euclidian distance
ld dist(const Ponto& p1, const Ponto& p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	Ponto p1, p2, planeta;
	int N;

	scanf("%Lf %Lf %Lf %Lf", &p1.x, &p1.y, &p2.x, &p2.y);
	scanf("%d", &N);

	Reta reta(p1, p2);

	ll o=0, l=0;
	ll ho=0, hl=0;
	ll c=0;
	rep(i,N){
		scanf("%Lf %Lf %llu", &planeta.x, &planeta.y, &planeta.h);

		int side = reta.side(planeta);
		if(side > 0){
			o++; ho += planeta.h;
		}else if(side < 0){
			l++; hl += planeta.h;
		}else{
			c++;
		}
	}

	printf("Relatorio Vogon #35987-2\n");
	printf("Distancia entre referencias: %.2Lf anos-luz\n", dist(p1, p2));
	printf("Setor Oeste:\n");
	printf("- %llu planeta(s)\n", o);
	printf("- %llu bilhao(oes) de habitante(s)\n", ho);
	printf("Setor Leste:\n");
	printf("- %llu planeta(s)\n", l);
	printf("- %llu bilhao(oes) de habitante(s)\n", hl);
	printf("Casualidades: %llu planeta(s)\n", c);

	return 0;
}