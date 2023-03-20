/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 147 - Dollars
 */
 
#include<stdio.h>
 
#define N 30002
 
static long long c[N];
static const unsigned coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
 
int main(){
    unsigned i, j;
    float n;
 
    c[0] = 1;
    for(i = 0; i < 11; ++i){
        for(j = coins[i]; j < N; ++j)
            c[j] += c[j - coins[i]];
    }
    
    /* Loop Split
 
    for(j = 5; j < N; ++j)
        c[j] += c[j - 5];
 
    for(j = 10; j < N; ++j)
        c[j] += c[j - 10];
 
    for(j = 20; j < N; ++j)
        c[j] += c[j - 20];
 
    for(j = 50; j < N; ++j)
        c[j] += c[j - 50];
 
    for(j = 100; j < N; ++j)
        c[j] += c[j - 100];
 
    for(j = 200; j < N; ++j)
        c[j] += c[j - 200];
 
    for(j = 500; j < N; ++j)
        c[j] += c[j - 500];
 
    for(j = 1000; j < N; ++j)
        c[j] += c[j - 1000];
 
    for(j = 2000; j < N; ++j)
        c[j] += c[j - 2000];
 
    for(j = 5000; j < N; ++j)
        c[j] += c[j - 5000];
 
    for(j = 10000; j < N; ++j)
        c[j] += c[j - 10000];
        */
 
    while(scanf("%f", &n) == 1 && n){
        // Rounding error fix
        unsigned coin = (unsigned)((n + 0.001) * 100);
 
        // 6 width justified including the input amount and 17 width afterwards including count
        printf("%6.2f%17lld\n", n, c[coin]);
    }
    return 0;
}
