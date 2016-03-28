// https://kknd.wordpress.com/2011/08/23/cadeias-de-markov-exemplo-pratico/
// http://www.mat.ufmg.br/~regi/gaalt/markov.pdf
// http://marathoncode.blogspot.com.br/2012/09/cadeia-de-markov.html
#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 1000000007

int main(){

	/// criando matrizes dinamicas para facilitar na função de exponenciação de matrizes
	int size = 26;
	double** T = (double **) malloc(size*sizeof(double*));
	double** R = (double **) malloc(size*sizeof(double*));
	double** aux;
	for (int i = 0; i < size; ++i){
		T[i] = (double*) malloc(size*sizeof(double));
		R[i] = (double*) malloc(size*sizeof(double));
	}

	int ev1,ev2,at,d,evt;
	double p1,p2;
	while(scanf("%d %d %d %d", &ev1, &ev2, &at, &d) && (ev1 != 0)){

		/// zerando matrizes
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				T[i][j] = R[i][j] = 0.0;

		/// simplificando o problema tornando o valor do D=1
		/// isso é feito para que as transições na matriz de transição
		/// sejam unitárias
		if(ev1%d != 0) ev1 += d;
		if(ev2%d != 0) ev2 += d;
		ev1 /= d; ev2 /= d; 

		/// o vampiro 1 irá ganhar quando capturar a vida do vamp 2
		evt = ev1 + ev2;

		p1 = at/6.0;
		p2 = 1.0-p1;


		/// criando o modelo da matriz de transição com as probabilidades
		T[0][0] = 1.0; /// estado em que o vamp1 perde tem p=1 
		T[evt][evt] = 1.0; /// estado em que o vamp 1 ganha tem p=1
		for (int i=1,j=2; i < evt; i++,j++){
			T[j-1][j] = p1;
			T[i][i-1] = p2;
		}

		/// exponenciando a matriz 2^1024
		for (int it = 1; it <= 1024; it=it*2)
		{
			for(int i=0; i <= evt; i++){
				for(int j=0; j<= evt; j++){
					R[i][j] = 0.0;     
					for(int k=0; k<= evt; k++){
						R[i][j] += T[i][k]*T[k][j];
					}
				}
			}

			/// trocando os ponteiros apenas, para envitar fazer loop de copia
			aux = T;
			T = R;
			R = aux;
		}

		printf("%.1lf\n", T[ev1][evt]*100.0);
	}

	return 0;

}
