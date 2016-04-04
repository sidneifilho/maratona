/// busca em largura por cada nível
#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 1000000007
#define INF 999999999
#define VMAX 1000

#define rep(i,N) for(int i=0;i<N;i++)

vector<int> adj[VMAX];
unordered_map<string, int> names;
unordered_map<int, string> names_inv;
vector<string> ans;
int N,K,V,u,v;

void bfs(int init, int V){
	int vis[V+1];
	memset(vis, 0, sizeof(vis));

	queue<ii> Q;
	Q.push(ii(init, 0)); /// vertice 0 é o Rerrison
	vis[init] = 1;

	while(!Q.empty()){
		ii top = Q.front(); Q.pop();
		int u = top.first, g = top.second;

		if(g+1 <= K){

			rep(i,adj[u].size()){

				/// adicionando os convidados com grau < K
				int v = adj[u][i];
				if(!vis[v]){
					ans.push_back(names_inv[v]);
					Q.push(ii(v, g+1));
					vis[v] = 1;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	string n1,n2;

	names["Rerisson"] = 0;

	cin >> N >> K;
	rep(i,N){
		cin >> n1 >> n2;

		/// iniciando a relação caso não exista
		if(names.find(n1) == names.end())
			names[n1] = names.size()-1;
		u = names[n1];
		names_inv[u] = n1;

		/// iniciando a relação caso não exista
		if(names.find(n2) == names.end())
			names[n2] = names.size()-1;
		v = names[n2];
		names_inv[v] = n2;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(0, names.size());

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	rep(i,ans.size()){
		cout << ans[i] << "\n";
	}

	return 0;
}