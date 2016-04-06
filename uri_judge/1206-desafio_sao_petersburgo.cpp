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
   
    int n;
    int wk_r, wk_c, r, row, col; /// white king
    char tab[8][8], tab_pos[8][8];
    char p, c;
    int pecas[10][2];
    while(scanf("%d", &n) != EOF){

        memset(tab, '.', sizeof(tab));
        memset(tab_pos, '.', sizeof(tab_pos));

        rep(i,n){

            scanf(" %c %c %d", &p, &c, &r);
            pecas[i][0] = 8-r;
            pecas[i][1] = int(c)-'a';

            tab_pos[pecas[i][0]][pecas[i][1]] = p;
        }

        rep(i,n){
            row = pecas[i][0];
            col = pecas[i][1];
            p = tab_pos[row][col];

            switch(p){
                case 'P':
                    if(row+1 < 8 && col+1 < 8) tab[row+1][col+1] = 'x';
                    if(row+1 < 8 && col-1 >= 0) tab[row+1][col-1] = 'x';

                    break;
                case 'B':

                    /// d1
                    for(int i=row-1, j=col+1; i >= 0 && j < 8; i--, j++){
                        tab[i][j] = 'x';
                        if(tab_pos[i][j] != '.') break;
                    }

                    /// d2
                    for(int i=row-1, j=col-1; i >= 0 && j >= 0; i--, j--){
                        tab[i][j] = 'x';
                        if(tab_pos[i][j] != '.') break;
                    }

                    /// d3
                    for(int i=row+1, j=col+1; i < 8 && j < 8; i++, j++){
                        tab[i][j] = 'x';
                        if(tab_pos[i][j] != '.') break;
                    }

                    /// d4
                    for(int i=row+1, j=col-1; i < 8 && j >= 0; i++, j--){
                        tab[i][j] = 'x';
                        if(tab_pos[i][j] != '.') break;
                    }

                    break;

                case 'T':

                    /// cima
                    for(int i=row-1; i >= 0; i--){
                        tab[i][col] = 'x';
                        if(tab_pos[i][col] != '.') break;
                    }

                    /// baixo
                    for(int i=row+1; i < 8; i++){
                        tab[i][col] = 'x';
                        if(tab_pos[i][col] != '.') break;
                    }

                    /// direita
                    for(int i=col+1; i < 8; i++){
                        tab[row][i] = 'x';
                        if(tab_pos[row][i] != '.') break;
                    }

                    /// esquerda
                    for(int i=col-1; i >= 0; i--){
                        tab[row][i] = 'x';
                        if(tab_pos[row][i] != '.') break;
                    }

                    break;

                case 'W':
                    /// diagonais
                    if(row+1 < 8 && col+1 < 8) tab[row+1][col+1] = 'x';
                    if(row+1 < 8 && col-1 >= 0) tab[row+1][col-1] = 'x';
                    if(row-1 >= 0 && col+1 < 8) tab[row-1][col+1] = 'x';
                    if(row-1 >= 0 && col-1 >= 0) tab[row-1][col-1] = 'x';

                    if(row-1 >= 0) tab[row-1][col] = 'x'; /// cima
                    if(row+1 < 8) tab[row+1][col] = 'x'; /// baixo
                    if(col-1 >= 0) tab[row][col-1] = 'x'; /// esquerda
                    if(col+1 < 8) tab[row][col+1] = 'x'; /// direita
                    
                    break;

                case 'R':

                    /// cima
                    for(int i=row-1; i >= 0; i--){
                        tab[i][col] = 'x';
                        if(tab_pos[i][col] != '.') break;
                    }

                    /// baixo
                    for(int i=row+1; i < 8; i++){
                        tab[i][col] = 'x';
                        if(tab_pos[i][col] != '.') break;
                    }

                    /// direita
                    for(int i=col+1; i < 8; i++){
                        tab[row][i] = 'x';
                        if(tab_pos[row][i] != '.') break;
                    }

                    /// esquerda
                    for(int i=col-1; i >= 0; i--){
                        tab[row][i] = 'x';
                        if(tab_pos[row][i] != '.') break;
                    }

                    /// d1
                    for(int i=row-1, j=col+1; i >= 0 && j < 8; i--, j++){
                        tab[i][j] = 'x';
                        if(tab_pos[i][j] != '.') break;
                    }

                    /// d2
                    for(int i=row-1, j=col-1; i >= 0 && j >= 0; i--, j--){
                        tab[i][j] = 'x';
                        if(tab_pos[i][j] != '.') break;
                    }

                    /// d3
                    for(int i=row+1, j=col+1; i < 8 && j < 8; i++, j++){
                        tab[i][j] = 'x';
                        if(tab_pos[i][j] != '.') break;
                    }

                    /// d4
                    for(int i=row+1, j=col-1; i < 8 && j >= 0; i++, j--){
                        tab[i][j] = 'x';
                        if(tab_pos[i][j] != '.') break;
                    }



                    break;
            }
        }

        scanf(" %*c %c %d", &c, &r);
        wk_r = 8-r;
        wk_c = int(c)-'a';

        int ans = 0;

        /// diagonais
        if(wk_r+1 < 8 && wk_c+1 < 8 && tab[wk_r+1][wk_c+1] == '.') ans |= 1; /// baixo direita
        if(wk_r+1 < 8 && wk_c-1 >= 0 && tab[wk_r+1][wk_c-1] == '.') ans |= 1;  /// baixo esquerda
        if(wk_r-1 >= 0 && wk_c+1 < 8 && tab[wk_r-1][wk_c+1] == '.') ans |= 1;  /// cima direita
        if(wk_r-1 >= 0 && wk_c-1 >= 0 && tab[wk_r-1][wk_c-1] == '.') ans |= 1;   /// cima esquerda
        if(wk_r-1 >= 0 && tab[wk_r-1][wk_c] == '.') ans |= 1; /// cima
        if(wk_r+1 < 8 && tab[wk_r+1][wk_c] == '.') ans |= 1; /// baixo
        if(wk_c-1 >= 0 && tab[wk_r][wk_c-1] == '.') ans |= 1; /// esquerda
        if(wk_c+1 < 8 && tab[wk_r][wk_c+1] == '.') ans |= 1; /// direita
        if(tab[wk_r][wk_c] == '.') ans |= 1; /// direita

        if(ans)
            printf("NAO\n");
        else 
            printf("SIM\n");
    }

    return 0;
}