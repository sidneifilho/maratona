/// problema da mochila maximizar os pedidos que duram mais tempo para serem entregues
#include <bits/stdc++.h>
using namespace std;

int N, W;
int wt[25];
int vt[25];

int knapsack(){
    int K[N+1][W+1];

    for (int i = 0; i <= N; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            if(i==0 || w==0)
                K[i][w] = 0;
            else if(wt[i-1] <= w)
                K[i][w] = max(vt[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[N][W]; /// esse elemento contem a solução 
}
 
// Driver Program to test above function
int main()
{
    while(cin >> N && N){
        cin >> W;

        for (int i = 0; i < N; ++i)
        {
            cin >> vt[i] >> wt[i]; // valor e peso do pedido
        }

        cout << knapsack() << " min."<< endl;
    }

    return 0;
}