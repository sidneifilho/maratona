#include <bits/stdc++.h>

#define ll long long unsigned int
#define MOD 1000000007
#define ii pair<int,int>

#define rep(i,N) for(int i=0;i<N;i++)

using namespace std;

int main (int argc, char const* argv[])
{
    
    int a,b,c,x,y,ans,qa,qe;
    int cartas[53];
    while(scanf("%d %d %d %d %d", &a,&b,&c,&x,&y) && (x)){

        /// setando as cartas que estão sendo usadas
        memset(cartas, 0, sizeof(cartas));
        cartas[a] = cartas[b] = cartas[c] = 1;
        cartas[x] = cartas[y] = 1;

        ans = -1;

        int princesa[] = {a,b,c};
        sort(princesa, princesa+3);

        /// analisando cada carta
        for(int i=1;i<=52;i++){
            if(!cartas[i]){

                int principe[] = {x,y,i};
                sort(principe, principe+3);

                qa = qe = 0; /// qe indica as vezes que o principe venceu

                /// menor da princesa contra a maior do principe
                if(princesa[0] > principe[2])
                    qa++;
                else
                    qe++;

                /// mairo da princesa contra a segunda maior do principe
                if(princesa[2] > principe[1])
                    qa++;
                else
                    qe++;

                /// segunda maior da princesa contra a menor do principe
                if(princesa[1] > principe[0])
                    qa++;
                else
                    qe++;

                if(qe >= 2){
                    ans = i;
                    break;
                }
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;
}