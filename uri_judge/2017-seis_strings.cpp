///haming distance - no URI faz parecer que devemos usar o Edit distance mas não é a solução
#include <bits/stdc++.h>

using namespace std;

int main() {

    int k;
    string first, str;

    cin >> first;
    cin >> k;

    int id = -1;
    int menor = 0;
    for (int i=1, d=0; i <= k; ++i)
    {
        cin >> str;

        for (int j = 0; j < first.size(); ++j)
            if(first[j] != str[j])
                d++;

        if(id == -1){
            id = i;
            menor = d;
        }else if(d < menor){
            id = i;
            menor = d;
        }
        
    }

    if(menor <= k){
        printf("%d\n", id);
        printf("%d\n", menor);
    }else
        printf("-1\n");

    return 0;
}