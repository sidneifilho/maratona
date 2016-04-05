#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 2147483647 // pow(2,31)-1
#define INF 999999999
#define VMAX 1111

#define rep(i,N) for(int i=0;i<N;i++)

vector<int> adj[VMAX];
int n;
int vis[VMAX];  

ll bfs(){

    memset(vis, 0, sizeof(vis));
    queue<int> Q;

    Q.push(0);
    vis[0] = 1;

    ll qt = 1;

    while(!Q.empty()){

        int u = Q.front(); Q.pop();

        rep(i, adj[u].size()){
            int v = adj[u][i];

            if(vis[v]==0){
                vis[v] = 1;
                Q.push(v);
                
                qt++;
            }
        }

    }

    return qt;
}

int main() {
    ios_base::sync_with_stdio(false);   

    ll a,b;
    while(scanf("%d", &n) && n){

        rep(i,VMAX)
            adj[i].clear();

        rep(i,n){
            scanf(" %*c%llu %*c%llu %*c", &a, &b);
            a--; b--;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        ll ans = bfs();
        printf("%llu\n", ans);
    }

    return 0;
}