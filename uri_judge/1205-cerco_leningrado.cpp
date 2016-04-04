#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXV = 1001;
int grafo[MAXV][MAXV];

int dijkstra(int origem, int destino, int v)
{
    int i, minimo, atual;
    int pred[MAXV], passou[MAXV], custo[MAXV];
    for (i = 0; i < v; i++)
    {
        pred[i] = -1;
        passou[i] = 0;
        custo[i] = INF;
    }
    
    custo[origem] = 0;
    atual = origem;
    while (atual != destino)
    {
        for (i = 0; i < v; i++){
            if (grafo[atual][i] != -1){
                if (custo[i] > grafo[atual][i]+custo[atual])
                {
                    custo[i] = custo[atual] + grafo[atual][i];
                    pred[i] = atual;
                }
            }
        }
                
        minimo = INF + 1;
        passou[atual] = 1;
        
        for (i = 0; i < v; i++){
            if ((custo[i] < minimo) && (!passou[i]))
            {
                minimo = custo[i];
                atual = i;
            }
        }
            
        if (minimo >= INF)
            return INF;
    }
    
    return custo[destino];
}


int main()
{
    int V, E, K, A;
    double P;
    int a, b, i, j, v, init, fim;
    int atirads[1000];
    while (scanf("%d %d %d %lf", &V, &E, &K, &P) != -1)
    {
        memset(grafo, 0xff, sizeof(grafo));
        for (i = 0; i < MAXV; i++)
            grafo[i][i] = 0;
        
        /// grafo bidirecionado
        for (i = 0; i < E; i += 1)
        {
            scanf("%d %d", &a, &b);
            a--; b--;
            grafo[a][b] = grafo[b][a] = 0;
        }
            
        scanf("%d", &A);
        memset(atirads, 0, sizeof(atirads));
        for (int i = 0; i < A; i++)
        {
            scanf("%d", &v);
            v--;
            atirads[v]++;
            
            // Preenche coluna
            for (int j = 0; j < V; j++)
                if (j != v && grafo[j][v] != -1)
                    grafo[j][v]++;
        }

        scanf("%d %d", &init, &fim);
        init--; fim--;

        A = atirads[init] + dijkstra(init, fim, V);
        
        if (K < A)
            printf("0.000\n");
        else
            printf("%.3lf\n", pow(P, A));
    }
    
    return 0;
}