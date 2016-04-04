#include <bits/stdc++.h>

#define ll long long unsigned int
#define MOD 1000000007
#define ii pair<int,int>

using namespace std;

int main (int argc, char const* argv[])
{
    
    int N,R,v,cnt=1,init,end,C;
    int pos[50005], values[50005];
    while(scanf("%d", &N) && N){

        for(int i=1;i<=N;i++)
            pos[i] = values[i] = i;

        scanf("%d", &R);
        while(R--){
            scanf("%d %d", &init, &end);

            for(int i=init, j=end, c=1; c <= (end-init+1)/2; j--, i++, c++){
                int ai = values[i];
                int aj = values[j];

                pos[ai] = j;
                pos[aj] = i;

                values[i] = aj;
                values[j] = ai;
            }

        }

        printf("Genome %d\n", cnt++);

        scanf("%d", &C);
        while(C--){
            scanf("%d", &v);
            printf("%d\n", pos[v]);
        }
    }
    
    return 0;
}