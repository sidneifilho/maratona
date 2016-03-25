// http://amatematicapura.blogspot.com.br/2011/02/area-do-floco-de-neve-de-von-koch.html
#include <bits/stdc++.h>

using namespace std;

#define ll long long unsigned int
#define pii pai<int,int>

int main(){

	double l, at;
	double f1 = sqrt(3.0)/2.0;
	double f2 = 8.0/5.0;
	while(scanf("%lf", &l) != EOF){
		at = l*l*f1;
		printf("%.2lf\n", (at*f2)/2.0);
	}

	return 0;
}