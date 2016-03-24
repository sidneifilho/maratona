/// Minimum spanning tree - Kruskal
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define ll long long unsigned int

#define VMAX 10005
#define EMAX 1000005

struct Edge{
	int o, d;
	ll w;
};

int cmp(const Edge& e1, const Edge& e2){
	return e1.w < e2.w;
}

struct subset{
	int parent, rank;
};

int V,E;
int qt_sets;
Edge edges[EMAX];
subset subsets[VMAX]; 

/// find-parent (path compression)
int findp(int i){
	if(subsets[i].parent != i)
		subsets[i].parent = findp(subsets[i].parent);

	return subsets[i].parent;
}

void unionr(int i, int j){

	int x = findp(i);
	int y = findp(j);

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

int main(int argc, char const *argv[])
{
	int r,numv,e,k,d;
	ll sumt,w;
	while(scanf("%d", &V) != -1){

		qt_sets = V;
		for(int i=0;i<V;i++)
			subsets[i].rank = 0, subsets[i].parent = i;

		E=0;
		for(int o=0;o<V-1;o++){
			r = scanf("%d", &k);

			for (int j = 0; j < k; ++j)
			{
				scanf("%d %llu", &d, &w);
				d--;
				edges[E].o = o; edges[E].d = d; edges[E].w = w;
				E++;
			}
		}

		sort(edges, edges+E, cmp); /// ordenando pelo menor custo

		//for (int i = 0; i < E; ++i)
		//{
		//	printf("%d %d %d\n", edges[i].o+1, edges[i].d+1, edges[i].w);
		//}

		/// Kruskal algorithm
		sumt=0; numv = 0;
		e = 0; /// edge que será analisada
		while(numv < V-1 && e < E){ /// criando a minimum spanning tree

			int i = findp(edges[e].o);
			int j = findp(edges[e].d);

			if(i != j){
				sumt += edges[e].w;
				numv++;
				qt_sets--;
				unionr(i,j);
			}

			e++;
		}

		printf("%d %llu\n", qt_sets, sumt);
	}

	return 0;
}