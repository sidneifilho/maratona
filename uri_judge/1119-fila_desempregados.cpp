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
    ios_base::sync_with_stdio(false); 
    cout << setiosflags (ios::fixed) << setprecision(2);

    int p1,p2,n,k,m,cnt,i,j,v1,v2,s1,s2;
    int values[30];
    while(scanf("%d %d %d", &n, &k, &m) && n){

        rep(i,n){
            values[i]=i+1;
        }

        p1 = 0;
        p2 = n-1;
        cnt = 0;
        while(cnt < n){

            /// procurando o elemento 1
            i=k;
            while(i > 0){
                if(values[p1] != 0){
                    i--;
                }
                if(i==0) s1 = p1;
                p1=(p1+1)%n;    
            }

            // procurando o elemento 2
            i=m;
            while(i > 0){
                if(values[p2] != 0){
                    i--;
                }
                if(i==0) s2 = p2;
                p2=(p2+n-1)%n;    
            }

            if(cnt > 0)
                printf(",");

            /// removendo elementos
            if(s1 != s2){
                printf("%3d%3d", values[s1], values[s2]);
                cnt+=2;
            }else{
                printf("%3d", values[s1]);
                cnt++;
            }

            values[s1] = values[s2] = 0;
        }
        printf("\n");

    }

    return 0;
}