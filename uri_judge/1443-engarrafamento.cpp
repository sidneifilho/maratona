#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 2147483647 // pow(2,31)-1
#define INF 999999999
#define VMAX 15

#define rep(i,N) for(int i=0;i<N;i++)

int main()
{
    double a = 1.0, d = 2.0; /// aceleração e desaceleração m/s²

    int n,t0,t1,tlast;
    double v0,v1,dt,dt2,s,t_v0;
    while(scanf("%d", &n) && n){

        scanf("%d %d", &t0, &t1);
        
        v0 = 0.0;
        s = 0.0;
        dt = t1-t0;
        if(dt + v0 > 10.0){ 
            dt = 10.0-v0;
            v1 = 10.0;
            s += v0*dt + (a*dt*dt)/2.0; /// aceleracao constante

            dt = t1 - (t0+dt);
            s += v1*dt; /// aceleracao igual a 0

        }else{
            dt = t1-t0;
            v1 = dt + v0;
            s += v0*dt + (a*dt*dt)/2.0; /// aceleracao constante
        }

        tlast = t1;
        v0 = v1;

        rep(i, n-1){
            scanf("%d %d", &t0, &t1);

            /// ****** desacelerando ****************
            if(t0 - tlast > 0){
                dt = t0-tlast;

                /// iremos calcular a distancia enquanto o carro está se movendo
                if(dt > v0/d) dt = v0/d; 

                s += v0*dt - (d*dt*dt)/2.0; /// desaceleracao constante
                v1 = v0-d*dt;
                v0 = v1;
            }

            /// ****** acelerando ****************
            dt = t1-t0;
            if(dt + v0 > 10.0){ 
                
                /// aceleracao constante
                dt = 10.0-v0;
                v1 = 10.0;
                s += v0*dt + (a*dt*dt)/2.0;

                /// aceleracao igual a 0
                dt = t1 - (t0+dt);
                s += v1*dt;

            }else{
                dt = t1-t0;
                v1 = dt + v0;
                s += v0*dt + (a*dt*dt)/2.0;
            }

            tlast = t1;
            v0 = v1;
        }

        printf("%.2lf\n", s);

    }

    return 0;
}