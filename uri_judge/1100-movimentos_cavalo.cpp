/// achar o menor caminho. Como os passos tem custo 1 apenas é feito umas busca em largura
#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define ii pair<int,int>
#define MOD 1000000007

#define rep(i,N) for(int i=0;i<N;i++)

struct nodo{
	int dist, r, c;

	nodo(){
		dist = r = c = 0;
	}

	nodo(int _r, int _c, int _dist){
		r = _r;
		c = _c;
		dist = _dist;
	}
};

int bfs(nodo init, nodo dest){
	int visited[10][10], r, c;
	memset(visited, 0, sizeof(visited));

	queue<nodo> fila;
	fila.push(init);
	visited[init.r][init.c] = 1;
	while(!fila.empty()){

		nodo horse = fila.front(); fila.pop();
		//printf("%d %d %d\n", horse.r, horse.c, horse.dist);

		/// mov 1
		r = horse.r - 2; c = horse.c + 1;
		if(r == dest.r && c == dest.c)
			return horse.dist + 1;
		else if((r >= 0 && r <= 7 && c >= 0 && c <= 7) && !visited[r][c]){
			fila.push(nodo(r, c, horse.dist+1));
			visited[r][c] = 1;
		}

		/// mov 2
		r = horse.r - 2; c = horse.c - 1;
		if(r == dest.r && c == dest.c)
			return horse.dist + 1;
		else if((r >= 0 && r <= 7 && c >= 0 && c <= 7) && !visited[r][c]){
			fila.push(nodo(r, c, horse.dist+1));
			visited[r][c] = 1;
		}

		/// mov 3
		r = horse.r + 2; c = horse.c + 1;
		if(r == dest.r && c == dest.c)
			return horse.dist + 1;
		else if((r >= 0 && r <= 7 && c >= 0 && c <= 7) && !visited[r][c]){
			fila.push(nodo(r, c, horse.dist+1));
			visited[r][c] = 1;
		}

		/// mov 4
		r = horse.r + 2; c = horse.c - 1;
		if(r == dest.r && c == dest.c)
			return horse.dist + 1;
		else if((r >= 0 && r <= 7 && c >= 0 && c <= 7) && !visited[r][c]){
			fila.push(nodo(r, c, horse.dist+1));
			visited[r][c] = 1;
		}

		/// mov 5
		r = horse.r + 1; c = horse.c + 2;
		if(r == dest.r && c == dest.c)
			return horse.dist + 1;
		else if((r >= 0 && r <= 7 && c >= 0 && c <= 7) && !visited[r][c]){
			fila.push(nodo(r, c, horse.dist+1));
			visited[r][c] = 1;
		}

		/// mov 6
		r = horse.r + 1; c = horse.c - 2;
		if(r == dest.r && c == dest.c)
			return horse.dist + 1;
		else if((r >= 0 && r <= 7 && c >= 0 && c <= 7) && !visited[r][c]){
			fila.push(nodo(r, c, horse.dist+1));
			visited[r][c] = 1;
		}

		/// mov 7
		r = horse.r - 1; c = horse.c + 2;
		if(r == dest.r && c == dest.c)
			return horse.dist + 1;
		else if((r >= 0 && r <= 7 && c >= 0 && c <= 7) && !visited[r][c]){
			fila.push(nodo(r, c, horse.dist+1));
			visited[r][c] = 1;
		}

		/// mov 6
		r = horse.r - 1; c = horse.c - 2;
		if(r == dest.r && c == dest.c)
			return horse.dist + 1;
		else if((r >= 0 && r <= 7 && c >= 0 && c <= 7) && !visited[r][c]){
			fila.push(nodo(r, c, horse.dist+1));
			visited[r][c] = 1;
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	nodo init, dest;
	int ans;
	string s, t;
	while(cin >> s >> t){

		init.r = int(s[1])-49; init.c = int(s[0])-97;
		dest.r = int(t[1])-49; dest.c = int(t[0])-97;

		if(init.r == dest.r  && init.c == dest.c)
			ans = 0;
		else
			ans = bfs(init, dest);

		printf("To get from %s to %s takes %d knight moves.\n", s.c_str(), t.c_str(), ans);
	}

	return 0;
}