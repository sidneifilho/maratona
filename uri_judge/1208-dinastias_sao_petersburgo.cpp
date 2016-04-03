#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(z,w) for(int z=0;z<w;z++)
 
const int MAXN1 = 100005;
const int MAXN2 = 100005;
const int MAXM = 15000000;
 
int n1, n2, edges, ult[MAXN1], ant[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];
 
void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(ult, ult + n1, -1);
}
 
void addEdge(int u, int v) {
    head[edges] = v;
    ant[edges] = ult[u];
    ult[u] = edges++;
}
 
void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = ult[u1]; e >= 0; e = ant[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}
 
bool dfs(int u1) {
    vis[u1] = true;
    for (int e = ult[u1]; e >= 0; e = ant[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}
 
int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
 
int main() {

    int n, m, a, b;
    while(scanf("%d %d", &n, &m) != -1){
    
        //cout << n << " " << m << endl;
        
        init(n,n);
        rep(i,m){
            scanf("%d %d", &a, &b);
            //cout << a << " " << b << endl;
            a--; b--;
            addEdge(a, b);
        }
        
        /// retornando a quantidade de aresta independentes       
        printf("%d\n", n - maxMatching());
    }    
}