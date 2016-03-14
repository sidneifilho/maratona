// A union by rank and path compression based program to detect cycle in a graph - 1527 - Guildas
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
 
struct subset
{
    int parent;
    int rank;
};

int N;
subset subsets[100010];
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;

        subsets[yroot].rank += subsets[xroot].rank; /// o rank do root será a soma de todos que estão no grupo

    }else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;

        subsets[xroot].rank += subsets[yroot].rank; /// o rank do root será a soma de todos que estão no grupo
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    }else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank += subsets[yroot].rank; /// o rank do root será a soma de todos que estão no grupo
        //subsets[xroot].rank++;
    }
}
 
// Driver program to test above functions
int main()
{

    int M, op, a, b;
    while(true){
        scanf("%d %d", &N, &M);
        if(N==0 && M==0) break;

        
        /// setando as guildas iniciais com suas pontuações
        for (int i = 0; i < N; ++i)
        {
            subsets[i].parent = i;
            scanf("%d", &subsets[i].rank);
        }

        int rroot = 0; /// guilda de rafael
        int qtv = 0; /// qt vitorias de Rafael

        /// analisando a operações e contabilizando o numero de vitorias de Rafael
        for (int i = 0; i < M; ++i)
        {
            scanf("%d %d %d", &op, &a, &b);
            a--; b--;

            if(op==1){ /// union
                Union(a, b);
                rroot = find(0);
            }else if(op == 2){ /// battle

                /// procurando qual a guila relacionada com o jogador
                int aroot = find(a);
                int broot = find(b);

                /// só iremos verificar o ganhador quando a guilda for relacionado a Rafael
                if(aroot == rroot && subsets[aroot].rank > subsets[broot].rank)
                    qtv++;
                else if(broot == rroot && subsets[broot].rank > subsets[aroot].rank)
                    qtv++;
            }
        }

        cout << qtv << endl;
    }
 
    return 0;
}