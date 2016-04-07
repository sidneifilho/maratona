#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 2147483647 // pow(2,31)-1
#define INF 999999999
#define NMAX 28005

#define rep(i,N) for(int i=0;i<N;i++)

int main(void) {
   
    int n, k;
    char va[26];
    char vb;
    string res;
    int running = 1, removeu;
    while(scanf("%d", &n) && n != 0){
        running = 1;

        rep(i,n){
            scanf(" %c", &va[i]);
        }

        res = "";
        stack<char> vs;
        k=0;
        rep(i, n){
            scanf(" %c", &vb);

            if(running){
                removeu = 0;

                if(k < n){

                    int j;
                    for(j=k;j<n;j++){

                        if(vb == va[j]){
                            printf("IR");
                            removeu = 1;
                            j++;
                            break;
                        }else{
                            if(vs.empty()){
                                printf("I");
                                vs.push(va[j]);
                            }else{

                                if(vs.top() == vb){
                                    printf("R");
                                    vs.pop();
                                    removeu=1;
                                    break;
                                }else{
                                    printf("I");
                                    vs.push(va[j]);
                                }
                            }
                        }
                    }
                    k=j;

                }else{
                    if(vs.top() == vb){
                        printf("R");
                        vs.pop();
                        removeu=1;
                    }else{
                        printf(" Impossible");
                        running = 0;
                    }

                }

                if(!removeu && running){
                    printf(" Impossible");
                    running = 0;
                }
            }            
        }
        printf("\n");
    }

    return 0;
}