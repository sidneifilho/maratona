/// problema da mochila disfarçado
/// verificar se existe uma combinação de pontes que
/// sejam igual a K
#include <bits/stdc++.h>

using namespace std;

vector<int> reg;
int R;
int K;
vector<int> m;

void calc_comb(){

    m.resize(K+1);
    m[0] = 1;
    for (int i = 0; i < R; i += 1)
    {
        if(reg[i] > 0){
            for (int j = K; j >= reg[i]; j--)
            {
                if(m[j-reg[i]] == 1){
                    m[j] = 1;
                }
            }
        }
    }
}

int main (int argc, char const* argv[])
{
    int c1, c2, result;
    while(scanf("%d %d", &R, &K) != -1){
    
        reg.resize(R);
        for (unsigned int i = 0; i < K; i += 1)
        {
            scanf("%d %d", &c1, &c2);
            reg[c1-1]++;
            reg[c2-1]++;
        }
    
        /// analisando se tem uma combinacao igual a k
        calc_comb();
        
        /// verificando a resposta
        if(m[K] == 1){
            printf("S\n");
        }else{
            printf("N\n");
        }
        
        reg.clear();
        m.clear();
    }
    
    return 0;
}