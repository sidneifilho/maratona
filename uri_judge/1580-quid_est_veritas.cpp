/// aritmética modular
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define ll long long unsigned int
#define MOD 1000000007

ll fastexp(ll a, ll b){

	ll x;

	if(b==0) return 1;
	if(b==1) return a;

	if(b%2==0){
		x = fastexp(a,b/2)%MOD;
		return (x*x)%MOD;
	}else{
		return (a*fastexp(a,b-1))%MOD;
	}
}

ll inv_mod(ll a){
  return fastexp(a, MOD-2);
}

int main (int argc, char* argv[]) {

	ll fat[1005], num, den, inv;
	fat[0] = 1;
	fat[1] = 1;
	for (int i = 2; i < 1005; ++i)
		fat[i] = (fat[i-1]*i)%MOD;

	int freq[26];
	string word;
	while(cin >> word){
		memset(freq, 0, sizeof(freq));

		/// analisando a letras repetidas
		for (int i = 0, p; i < word.size(); ++i)
		{
			p = int(word[i])-65;
			freq[p]++;
		}

		num = fat[word.size()]; /// numerador

		/// calculando o denominador
		den = 1;
		for(int i=0; i<26;i++){
			if(freq[i] > 0)
				den = (den*fat[freq[i]])%MOD;
		}

		/// calculando o inverso modular pois é preciso devido as propriedades da
		/// aritmetica modular
		inv = inv_mod(den);

		printf("%llu\n", (num*inv)%MOD);
	}

    return 0;
}