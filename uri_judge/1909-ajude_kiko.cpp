/// matematico
#include <bits/stdc++.h>

using namespace std;

int gcd (int x, int y) {
    return y ? gcd (y, x % y) : abs (x);
}

int mmc (int x, int y) {
    if (x && y)
        return (abs (x) / gcd(x, y) * abs (y));
    else
        return (int) abs (x | y);
}

int main() {
   
   	int b,t;
	while(scanf("%d %d", &b, &t) && (b+t)){

		set<int> bolas;

		int m = 1;
		for (int i = 0,v; i < b; ++i)
		{
			cin >> v;
			bolas.insert(v);

			m = mmc(v,m);
		}

		bool res = false;
		for (int i = 2; i <= t; ++i)
		{
			if(bolas.count(i)==0 && mmc(m, i) == t){
				m=i;
				res = true;
				break;
			}
		}

		if(res){
			printf("%d\n", m);
		}else{
			printf("impossivel\n");
		}
	}

    return 0;
}