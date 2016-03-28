#include <bits/stdc++.h>
#include <cfloat>

using namespace std;

#define ll long long unsigned int
#define ld long double
#define ii pair<int,int>
#define MOD 100000007 
#define VMAX 105
const int INF = 0x3F3F3F3F;

#define rep(i,N) for(int i=0;i<N;i++)


int V;
double D[VMAX][VMAX];

/* A utility function to print solution */
void printSolution(double dist[][VMAX])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%s ", "INF");
            else
                printf ("%.2lf ", dist[i][j]);
        }
        printf("\n");
    }
}

void floyd(){

	/// algoritmo
	rep(k,V)
		rep(i,V){
			if(i == k) continue;

			rep(j,V){
				 if( j == k || j == i ) continue;

				/// pegar o caminho com maior probabilidade
				/// as probs são multiplicadas pois são condicionadas
				if(D[i][k] && D[k][j] && D[i][j] < D[i][k]*D[k][j]){
					D[i][j] = D[i][k]*D[k][j];
				}
			}
		}
}
int main()
{ 
	int u,v,E;
	double p;
	while(scanf("%d", &V) && (V)){
		scanf("%d", &E);

		memset(D, 0.0, sizeof(D));

		rep(i,E){
			scanf("%d %d %lf", &u, &v, &p);
			u--; v--;
			D[u][v] = D[v][u] = p*0.01;
		}

		floyd();

		printf("%.6lf percent\n", D[0][V-1]*100.0);
	}

   	return 0;
}