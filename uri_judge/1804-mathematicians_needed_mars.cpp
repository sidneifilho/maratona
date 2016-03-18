/// fenwick tree BIT
#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & (-S))

int n;
int val[100005];
int t[100005];

//void ft_create(int n){ t.assign(n+1, 0); } // initially with n+1 zeros

int ft_rsq(int b){ 
    int sum = 0;

    for (;b; b -= LSOne(b)) sum += t[b]; /// O(logn)

    return sum;
}

void ft_adjust(int k, int v){
    for (;k <= n; k += LSOne(k)) t[k] += v; 
}

int main() {
    
    scanf("%d", &n);
    t[0] = 0;

    for (int i = 1; i <= n; ++i){
        scanf("%d", &val[i]);
        ft_adjust(i, val[i]);
    }

    int v;
    char o;
    while(cin >> o){
        cin >> v;
        if(o == '?'){
            printf("%d\n", ft_rsq(v-1));
        }else{
            ft_adjust(v, -val[v]);
            val[v] = 0;
        }
    }

    return 0;
}