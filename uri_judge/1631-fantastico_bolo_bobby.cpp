/// ponto, reta, distancia entre ponto e
/// reta e verificação do lado do ponto em relação a reta
#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 1000000007
#define INF 999999999
#define VMAX 255

#define rep(i,N) for(int i=0;i<N;i++)

struct Ponto{
	double x, y;

	Ponto():x(0.0),y(0.0){}

	Ponto(double _x, double _y):x(_x),y(_y){}
};

struct Reta{
	double a, b, c;

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

double dist(const Ponto& p, const Reta& r){
	return fabs(r.a*p.x + r.b*p.y + r.c)/sqrt(r.a*r.a + r.b*r.b);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	int N;
	Ponto pontos[105];
	double ans;
	while(scanf("%d", &N) && N != 0 ){

		rep(i, N){
			scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
		}

		ans = DBL_MAX;

		/// analisando as combinações de pontos e verificando
		/// qual separa melhor
		for(int i=0;i<N;i++){
			for (int j=i+1;j<N;++j){

				Reta reta(pontos[i], pontos[j]);

				double sum_esq = 0.0, sum_dir = 0.0;
				rep(k, N){

					int side = reta.side(pontos[k]);

					if(side > 0){
						sum_esq += dist(pontos[k], reta);
					}else if(side < 0){
						sum_dir += dist(pontos[k], reta);
					}
				}

				ans = min(ans, fabs(sum_esq-sum_dir));
			}
		}

		printf("%.3lf\n", ans);

	}

	return 0;
}