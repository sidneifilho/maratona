// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

int primev[3502];
 
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    vector<int> prime_vec(n+1, 1);
 
    int size=0;
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime_vec[p] == 1)
        {            
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime_vec[i] = 0;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
        if (prime_vec[p])  
            primev[size++] = p;
}
 
// Driver Program to test above function
int main()
{
    SieveOfEratosthenes(32650);

    while(true){
        int n;
        scanf("%d", &n);
        if(n==0) break;

        int r = 0;
        for (int i = 1; i <= n; ++i){
            r = (r+primev[n-i])%i;
        }

        printf("%d\n", r+1);
    }

    return 0;
}