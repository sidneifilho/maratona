/// Floyd-Warshell ao inves de djisktra pois o número de consultas é alto
#include <bits/stdc++.h>
#include <cfloat>

using namespace std;

const int INF = 0x3F3F3F3F ;
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 100000007 
#define VMAX 105

#define rep(i,N) for(int i=0;i<N;i++)

int V;
map<string, int> cities; /// map do nome da cidade para a posição no grafo
map<int, string> cities_inv;
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

				if(D[i][k] + D[k][j] < D[i][j]){
					D[i][j] = D[i][k] + D[k][j];
					pi[i][j] = pi[i][k];
				}
			}
}

void path_floyd(int u, int v){

	if(D[u][v] == INF)
		return ;

	printf("%s", cities_inv[u].c_str());
	while(u != v){
		u = pi[u][v];
		printf(" %s", cities_inv[u].c_str());
	}
	printf("\n");
}

int main()
{ 
	int C,R,u,v;
	string name, c1, c2, emp;

	scanf("%d", &C);

	while(C--){
		
		cities.clear();
		cities_inv.clear();

		scanf("%d", &V);
		rep(i,V){ cin >> name; cities[name]=i; cities_inv[i] = name; }

		rep(i,V){
			rep(j,V){
				scanf("%d", &D[i][j]);
				if(D[i][j] == -1)
					D[i][j] = INF;
			}
		}

		//printSolution(D);

		floyd();

		//printSolution(D);

		/// lendo as consultas
		scanf("%d", &R);
		rep(i,R){
			cin >> emp >> c1 >> c2;
			u = cities[c1]; v = cities[c2];

			if(D[u][v] != INF){
				printf("Mr %s to go from %s to %s, you will receive %d euros\n",
					emp.c_str(), c1.c_str(), c2.c_str(), D[u][v]);

				printf("Path:");
				if(u == v){
					printf("%s %s\n", c1.c_str(), c2.c_str());
				}else{
					path_floyd(u, v);
				}

			}else{
				printf("Sorry Mr %s you can not go from %s to %s\n",
					emp.c_str(), c1.c_str(), c2.c_str());
			}
		}
	}



   	return 0;
}