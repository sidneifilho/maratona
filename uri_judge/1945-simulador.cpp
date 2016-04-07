#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 2147483647 // pow(2,31)-1
#define INF 999999999
#define NMAX 28005

#define rep(i,N) for(int i=0;i<N;i++)

vector<string> read_line(char delimiter=' ') {

    vector<string> internal;
    
    string str;
    bool res = getline(cin, str);
    if(!res) return internal;

    string tok;
    stringstream ss(str);

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
  
    return internal;
}

bool isInt(const string& s, int base){
   if(s.empty() || std::isspace(s[0])) return false ;
   char * p ;
   strtol(s.c_str(), &p, base) ;
   return (*p == 0) ;
}

int main(void) {
    ios_base::sync_with_stdio(false); 
    cout << setiosflags (ios::fixed) << setprecision(2);

    unordered_map<string, int> variaveis;
    int ans = 0, v1,v2;
    string var,op,aux;

    vector<string> line = read_line();

    while(!line.empty()){

        if(line.size() == 3){
            variaveis[line[0]] = atoi(line[2].c_str());
            ans = atoi(line[2].c_str());

        }else {

            v1 = v2 = 0;
            if(isInt(line[2], 10)){
                v1 = atoi(line[2].c_str());
            }else{
                v1 = variaveis[line[2]];
            }

            if(isInt(line[4], 10)){
                v2 = atoi(line[4].c_str());
            }else{
                v2 = variaveis[line[4]];
            }


            variaveis[line[0]] = v1+v2;
            ans = v1+v2;
        }

        line = read_line();
    }

    cout << ans << "\n";

    return 0;
}