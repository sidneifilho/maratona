// Teorema de pitagoras GDC
#include <cstdio>

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int gcd_tri(int x, int y, int z) {
    return gcd(x, gcd(y, z));
}

int main() {
    int x, y, z;
    bool res;

    while (scanf("%d %d %d", &x, &y, &z) != EOF) {

    	res = false;
    	if (x > y && x > z) res = x * x == (y * y) + (z * z);
	    else if (y > z) res = y * y == (x * x) + (z * z);
	    else res = z * z == (x * x) + (y * y);

        printf("tripla");

        if (res) {
            printf(" pitagorica");

            if (gcd_tri(x, y, z) == 1) {
                printf(" primitiva");
            }
        }
        puts("");
    }

    return 0;
}