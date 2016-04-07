#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 2147483647 // pow(2,31)-1
#define INF 999999999
#define NMAX 28005

#define rep(i,N) for(int i=0;i<N;i++)

stringstream ss;
void line(){
	string str;
	ss.clear();
	getline(cin, str);
	ss.str(str);
}

struct brinquedo {
	int qt;
	double peso;
};

int main(void) {
    ios_base::sync_with_stdio(false); 
    cout << setiosflags (ios::fixed) << setprecision(2);

    int Y,T,qt;
    double W,peso_t;
    string l,name;
    map<string, brinquedo> brinquedos;

    line(); ss >> Y;

    while(Y--){

    	line(); ss >> T;

    	while(T--){
    		line(); name = ss.str();
    		line(); ss >> brinquedos[name].peso;
    	}

    	line(); ss >> W;

    	peso_t = 0.0;
    	while(true){
    		line(); name = ss.str();

    		line(); ss >> qt;

    		/// ultima linha
    		if(name == "-"){
    			break;
    		}

    		if(brinquedos.find(name) == brinquedos.end()){
    			cout << "NAO LISTADO: " << name << "\n";
    		}else{
    			peso_t += brinquedos[name].peso * qt;
    		}
    	}

    	cout << "Peso total: " << peso_t << " kg\n";
    	cout << "Numero de trenos: " << int(ceil(peso_t/W));
    	cout << "\n\n";
    	brinquedos.clear();
    }
  

    return 0;
}