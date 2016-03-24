/// Minimum spanning tree - Kruskal
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define ll long long unsigned int

#define VMAX 50009
#define EMAX 60009

struct Edge{
	int o, d;
	int w;
};

int cmp(const Edge& e1, const Edge& e2){
	return e1.w < e2.w;
}

struct subset{
	int parent, rank;
};

int V,E;
Edge edges[EMAX];
subset subsets[VMAX]; 

/// find-parent (path compression)
int findp(int i){
	if(subsets[i].parent != i)
		subsets[i].parent = findp(subsets[i].parent);

	return subsets[i].parent;
}

int main(int argc, char const *argv[])
{
	int r,droot,oroot,numv,e;
	int sumt,x,y;
	while(scanf("%d %d", &V, &E) && (V+E)){

		for(int i=0;i<V;i++)
			subsets[i].rank = 0, subsets[i].parent = i;

		for(int i=0;i<E;i++)
			r = scanf("%d %d %d", &edges[i].o, &edges[i].d, &edges[i].w);

		sort(edges, edges+E, cmp); /// ordenando pelo menor custo

		/// result
		sumt=0; numv = 0;
		e = 0; /// edge que será analisada
		while(numv < V-1 && e < E){ /// criando a minimum spanning tree

			oroot = findp(edges[e].o);
			droot = findp(edges[e].d);

			if(oroot != droot){
				sumt += edges[e].w;
				numv++;

				x = findp(oroot);
				y = findp(droot);

				/// union by rank
				if(subsets[x].rank < subsets[y].rank){
					subsets[x].parent = y;
				}else if(subsets[x].rank > subsets[y].rank){
					subsets[y].parent = x;
				}else{ 
					subsets[y].parent = x;
					subsets[x].rank++;
				}
			}

			e++;
		}

		printf("%d\n", sumt);
	}

	return 0;
}