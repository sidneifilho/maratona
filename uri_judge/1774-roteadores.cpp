#include <bits/stdc++.h>
#include <cfloat>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 100000007 
#define VMAX 65

#define rep(i,N) for(int i=0;i<N;i++)

int V,E;
int D[VMAX], pi[VMAX], visited[VMAX];
vector<ii> adj[VMAX]; //(u,v) -> adj[u][i] = (v,cost)

int prim(){

	int ans=0;

	rep(v,V){ D[v] = INT_MAX; pi[v] = -1; visited[v]=0; }
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	D[0] = 0; Q.push(ii(0,0)); /// adicionando o primeiro vertice

	while(!Q.empty()){
		ii top = Q.top(); Q.pop();
		int u = top.second, d = top.first;

		if(!visited[u]){
			ans += d; visited[u] = 1;
			rep(i, adj[u].size())
			{
				int v = adj[u][i].first, cost = adj[u][i].second; 
				if(!visited[v] && (D[v] > cost)){
					D[v] = cost; pi[v] = u;
					Q.push(ii(D[v], v));
				}
			}

		}
	}

	return ans;
}

int main()
{ 
	int u,v,w,r;

	while(scanf("%d %d", &V, &E) != EOF){

		rep(i,E){
			r=scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			adj[u].push_back(ii(v, w));
			adj[v].push_back(ii(u, w));
		}

		/// aplicando prim para gerar a MST
		int res = prim();
		printf("%d\n", res);
	}

   	return 0;
}