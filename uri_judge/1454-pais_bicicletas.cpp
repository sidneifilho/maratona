/// minmax floyd warshell
#include <bits/stdc++.h>
#include <cfloat>

using namespace std;

const int INF = 0x3F3F3F3F;
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 100000007 
#define VMAX 105

#define rep(i,N) for(int i=0;i<N;i++)

int V;
int D[VMAX][VMAX], pi[VMAX][VMAX];

/* A utility function to print solution */
void printSolution(int dist[][VMAX])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floyd(){
	
	/// iniciando a lista do caminho de i a j
	rep(i,V)
		rep(j,V)
			pi[i][j] = j;

	/// algoritmo
	rep(k,V)
		rep(i,V)
			rep(j,V){
				if(i == j)
					continue;

				/// pegando a maior altura entre i-k e k-j
				/// porém pegando o menor caminho de i-j
				D[i][j] = min(D[i][j], max(D[i][k], D[k][j]));
			}
}
int main()
{ 
	int inst=0,u,v,ans=0,h,k,E;
	while(scanf("%d %d", &V, &E) && (V+E)){

		memset(D, INF, sizeof(D));
		rep(i,V)
			D[i][i] = 0;

		rep(i,E){
			scanf("%d %d %d", &u, &v, &h);
			u--; v--;
			D[u][v] = D[v][u] = h;
		}

		floyd();

		printf("Instancia %d\n", ++inst);
		
		scanf("%d", &k);
		rep(i,k){
			scanf("%d %d", &u, &v);
			u--; v--;

			if(D[u][v] != INF && u != v){

				/// verificando a maior altura no menor caminho entre u e v
				int ant = u;
				ans = -INF;
				while(u != v){
					u = pi[u][v];
					ans = max(ans, D[ant][u]);
					ant = u;
				}
				printf("%d\n", ans);

			}else if(u == v){ /// se u for igual a v a maior altura é zero
				printf("0\n");
			}

		}
		printf("\n");
	}

   	return 0;
}