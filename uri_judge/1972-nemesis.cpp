/// dijkstra - 1972 Nêmesis
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < n; ++i)
#define NMAX 250005
#define ii pair<int, int >

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

vector<ii> adj[NMAX]; // (u,v) -> adj[u][v] = (v, cost)
int N; int D[NMAX], pi[NMAX];

void dijkstra(int s){

	rep(i,N){ D[i] = INF; pi[i] = -1; }
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	D[s] = 0; Q.push(ii(0, s));

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
	string row;
	int R, C;
	cin >> R >> C;

	int s, d;
	N=0;
	char lab[R][C]; 
	pair<int, int> vertices[R][C];
	for (int i = 0; i < R; ++i){
		cin >> row;

		for (int j = 0; j < row.size(); ++j){
			lab[i][j] = row[j];

			if(lab[i][j] != '#'){
				int v = N++;
				
				int cost = 0;
				if(lab[i][j] == '.' || lab[i][j] == 'H' || lab[i][j] == 'E')
					cost = 0;
				else
					cost = int(lab[i][j])-48;

				/// verificando se o nodo atual é origem ou destino
				if(lab[i][j] == 'H') s = v;
				else if(lab[i][j] == 'E') d = v;

				vertices[i][j] = ii(v, cost);

			}else
				vertices[i][j] = ii(-1,-1);
		}
	}

/*
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			printf("%d,%d ", vertices[i][j].first, vertices[i][j].second);
		}
		printf("\n");
	}
	cout << endl;
*/

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if(lab[i][j] != '#'){
				int u = vertices[i][j].first;

				/// fazendo conexão com o nodo superior
				if(i-1 >= 0 && lab[i-1][j] != '#'){
					int v = vertices[i-1][j].first;
					int cost = vertices[i-1][j].second;

					adj[u].push_back(ii(v, cost));

					//printf("con %d-%d: %d\n", u, v, cost);
				}

				/// fazendo conexão com o nodo inferior
				if(i+1 < R && lab[i+1][j] != '#'){
					int v = vertices[i+1][j].first;
					int cost = vertices[i+1][j].second;

					adj[u].push_back(ii(v, cost));

					//printf("con %d-%d: %d\n", u, v, cost);
				}

				/// fazendo conexão com o nodo da esquerda
				if(j-1 >= 0 && lab[i][j-1] != '#'){
					int v = vertices[i][j-1].first;
					int cost = vertices[i][j-1].second;

					adj[u].push_back(ii(v, cost));

					//printf("con %d-%d: %d\n", u, v, cost);
				}

				/// fazendo conexão com o nodo da direita
				if(j+1 < C && lab[i][j+1] != '#'){
					int v = vertices[i][j+1].first;
					int cost = vertices[i][j+1].second;

					adj[u].push_back(ii(v, cost));

					//printf("con %d-%d: %d\n", u, v, cost);
				}
			}
		}
	}

	/// verificando o caminho da origem até o vertice C
	dijkstra(s);
	int res = D[d];
	if(res == INF) printf("ARTSKJID\n");
	else printf("%d\n", res);

	return 0;
}