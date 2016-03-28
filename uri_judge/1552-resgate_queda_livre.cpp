#include <bits/stdc++.h>
#include <cfloat>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define di pair<double,int>
#define MOD 100000007 
#define VMAX 505

#define rep(i,N) for(int i=0;i<N;i++)

struct Ponto{
	double x, y;
};

/// euclidean distance
double dist(const Ponto& p1, const Ponto& p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int V;
Ponto pos[VMAX]; /// posição das pessoas 
double D[VMAX];
int pi[VMAX], visited[VMAX];

double prim(){

	double ans = 0.0;

	rep(v,V){ D[v] = INT_MAX; pi[v] = -1; visited[v]=0; }
	priority_queue<di, vector<di>, greater<di> > Q;
	D[0] = 0; Q.push(di(0,0)); /// adicionando o primeiro vertice

	while(!Q.empty()){
		di top = Q.top(); Q.pop();
		int u = top.second;
		double d = top.first;

		if(!visited[u]){
			ans += d;
			visited[u] = 1;
			
			/// como sabe-se que todos os verticies estão conectados
			/// não precisa-se de uma lista ou matriz de adjacencia
			/// é só iterar para todos os vertices
			for (int v = 0; v < V; ++v)
			{
				if(u != v){ /// o vertice u não tem conexão para ele mesmo
					double cost = dist(pos[u], pos[v]); /// custo da conexão é a dist entre as pessoas
					if(!visited[v] && (D[v] > cost)){
						D[v] = cost; pi[v] = u;
						Q.push(di(D[v], v));
					}
				}
			}

		}
	}

	return ans;
}

int main()
{ 
	int T;
	scanf("%d", &T);

	while(T--){

		scanf("%d", &V);
		for (int i = 0; i < V; ++i)
			scanf("%lf %lf", &pos[i].x, &pos[i].y);

		/// aplicando prim para gerar a MST
		double res = prim();
		printf("%.2lf\n", res/100.0);
	}

   	return 0;
}