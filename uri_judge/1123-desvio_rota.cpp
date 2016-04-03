// dijkstra. Grafo modificado devido as restrições do problema
#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 1000000007

#define VMAX 255
#define INF 999999999

#define rep(i,N) for(int i=0;i<N;i++)

vector<ii> adj[VMAX];
int D[VMAX];
int V, R, E;

int dijkstra(int init){

	rep(i,V){ D[i]=INF; }

	priority_queue<ii, vector<ii>, greater<ii> > Q;
	Q.push(ii(0, init)); D[init] = 0;

	while(!Q.empty()){
		ii top = Q.top(); Q.pop();
		int u = top.second, d = top.first;

		if(d <= D[u]){
			rep(i, adj[u].size()){
				int v = adj[u][i].first, cost = adj[u][i].second;
				
				if(D[u] + cost < D[v]){
					D[v] = D[u] + cost;
					Q.push(ii(D[v], v));
				}
			}
		}
	}

	return D[R-1];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	int a,b,cost,K,min_cost;
	while(scanf("%d %d %d %d", &V, &E, &R, &K) && V != 0){

		rep(i,V)
			adj[i].clear();

		rep(i,E){
			scanf("%d %d %d", &a, &b, &cost);

			/// as duas cidades estão fora da rota
			if(a >= R && b >= R){
				adj[a].push_back(ii(b, cost));
				adj[b].push_back(ii(a, cost));
				//printf("%d-%d: %d\n", a, b, cost);
			}

			/// se a primeira cidade não pertencer a rota e a segunda sim
			/// iremos adicionar uma aresta direcionada de a para b
			if(a >= R && b < R){
				adj[a].push_back(ii(b, cost));
				//printf("%d->%d: %d\n", a, b, cost);
			}

			/// mesmo caso que o anterior
			if(a < R && b >= R){
				adj[b].push_back(ii(a, cost));
				//printf("%d<-%d: %d\n", a, b, cost);
			}

			/// as duas cidades pertencem a rota e são consecutivas
			if(a < R && b < R && abs(a-b) == 1){
				adj[a].push_back(ii(b, cost));
				adj[b].push_back(ii(a, cost));
				//printf("%d-%d: %d\n", a, b, cost);
			}
		}

		int ans = dijkstra(K);
		printf("%d\n", ans);
	}

	return 0;
}