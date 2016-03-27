#include <bits/stdc++.h>

using namespace std;

string entrada;

int esquerda(int pos)
{
    char lido = entrada[pos];

    if(pos < 0)
         return -1;   
    
    if (lido == 'p'){
        entrada[pos] = 'q';
        pos--;
        pos = esquerda(pos);
        if (pos < 0)
            return pos;
    }

    if (lido == 's'){
        entrada[pos] = 'r';
        pos--;
        pos = esquerda(pos);
        if (pos < 0)
            return pos;
    }

    if (lido == 'q')
         entrada[pos] = 'p';

    if (lido == 'r')
         entrada[pos] = 's';
    
    return pos;

}

int direita(int pos)
{
    char lido = entrada[pos];

    if(pos < 0)
         return -1;   
    
    if (lido == 'r'){
        entrada[pos] = 's';
        pos--;
        pos = direita(pos);
        if (pos < 0)
            return pos;
    }

    if (lido == 'q'){
        entrada[pos] ='p';
        pos--;
        pos = direita(pos);
        if (pos < 0)
            return pos;
    }

    if (lido == 'p')
         entrada[pos] = 'q';

    if (lido == 's')
         entrada[pos] = 'r';
    
    return pos;
}

int cima(int pos)
{
    char lido = entrada[pos];
    
    if(pos < 0)
         return -1;   
    
    if (lido == 'p'){
        entrada[pos] = 's';
        pos--;
        pos = cima(pos);
        if (pos < 0)
            return pos;
    }

    if (lido == 'q'){
        entrada[pos] = 'r';
        pos--;
        pos = cima(pos);
        if (pos < 0)
            return pos;
    }

    if (lido == 's')
         entrada[pos] = 'p';

    if (lido == 'r')
         entrada[pos] = 'q';

    return pos;
}

int baixo(int pos)
{
    char lido = entrada[pos];
     
    if(pos < 0)
         return -1;   
    
    if (lido == 's'){

        entrada[pos]='p';
        pos--;
        pos = baixo(pos);
        
        if ( pos < 0)
            return pos;
    }

    if (lido == 'r'){
        entrada[pos] = 'q';
        pos--;
        pos = baixo(pos);
        if (pos < 0 )
            return pos;
    }

    if (lido == 'p')
         entrada[pos] = 's';

    if (lido == 'q')
         entrada[pos] = 'r';

    return pos;
}

void imprimeSaida(int pos){
    if(pos >= 0){
        cout << "m" << entrada;
    }else{
        cout << "<none>";
    }
}

int main(){

    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
    
        string lido;
        cin >> lido;
        
        lido.erase(lido.begin());
        
        entrada = lido;
        int pos = entrada.size()-1;
        int posSaida;
        posSaida = cima(pos);
        imprimeSaida(posSaida);

        cout << " ";
        entrada = lido;
        posSaida = baixo(pos);
        imprimeSaida(posSaida);

        cout << " ";
        entrada = lido;
        posSaida = esquerda(pos);
        imprimeSaida(posSaida);

        cout << " ";
        entrada = lido;
        posSaida = direita(pos);
        imprimeSaida(posSaida);
        cout << endl;
    }

    return 0;
}
