/// dijkstra
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < n; ++i)
#define NMAX 10005
#define ii pair<int, int>

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

vector<ii> adj[NMAX]; // (u,v) -> adj[u][v] = (v, cost)
int N; int D[NMAX], pi[NMAX];

void dijkstra(int s){
	rep(i,N){ D[i] = INF; pi[i] = -1; }
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	D[s] = 0; Q.push(ii(0,s));

	while(!Q.empty()){
		ii top = Q.top(); Q.pop();

		int u = top.second, d = top.first;
		if(d <= D[u]){
			rep(i, adj[u].size()){
				int v = adj[u][i].first, cost = adj[u][i].second;
				if(D[v] > D[u] + cost){
					D[v] = D[u] + cost;
					pi[v] = u;
					Q.push(ii(D[v], v));
				}
			}
		}
	}
} 

int main(int argc, char *argv[])
{
	int E, a, b, d;
	scanf("%d %d", &N, &E);

	/// inserindo em um grafo auxiliar
	vector<ii> adj_aux[N+1];
	rep(i,E){
		scanf("%d %d %d", &a, &b, &d);
		a--; b--;

		adj_aux[a].push_back(ii(b, d));
		adj_aux[b].push_back(ii(a, d));
	}

	/// criando um novo grafo apenas com numero pares de conexões por causa do problema
	/// os caminhos serão caminhos pares para chegar de um vertice a outro
	for (int i = 0; i < N; ++i){

		for (int j = 0; j < adj_aux[i].size(); ++j){

			int v = adj_aux[i][j].first;
			int cost = adj_aux[i][j].second;

			for (int k = 0; k < adj_aux[v].size(); ++k){
				int u = adj_aux[v][k].first;
				int newc = cost + adj_aux[v][k].second;
				if(i == u) continue;

				adj[i].push_back(ii(u, newc));
			}
		}
	}

	/// verificando o caminho da origem até o vertice C
	dijkstra(0);
	int res = D[N-1];
	if(res == INF) printf("-1\n");
	else printf("%d\n", res);

	return 0;
}