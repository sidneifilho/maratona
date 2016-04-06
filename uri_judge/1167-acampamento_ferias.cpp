#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 2147483647 // pow(2,31)-1
#define INF 999999999
#define NMAX 28005

#define rep(i,N) for(int i=0;i<N;i++)

struct aluno{
    string name;
    int p;
};

int main() {
    ios_base::sync_with_stdio(false);   

    vector<aluno> alunos;
    aluno a;
    int n;
    while(cin >> n && n){

        alunos.resize(n);

        rep(i,n){
            cin >> alunos[i].name >> alunos[i].p;
        }

        int pos = 0, p = alunos[0].p;
        while (n > 1)
        {
            if (p % 2 == 1)
                pos = (pos + p) % n;
            else{

                pos = (pos - (p % n)) % n; 
                if (pos < 0)
                    pos = n + pos;
            }
            
            p = alunos[pos].p;
            alunos.erase(alunos.begin() + pos);
            
            if (p % 2 == 1)
                pos--;
            n--;
        }

        cout << "Vencedor(a): "<< alunos[0].name << "\n";

        alunos.clear();
    }

    return 0;
}