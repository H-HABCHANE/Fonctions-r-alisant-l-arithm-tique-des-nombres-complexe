#include <stdio.h>
#include <time.h>

// Version classique
long long powmod_classic(long long a, long long e, long long n) {
    long long result = 1;
    for (long long i = 0; i < e; i++) {
        result = (result * a) % n;
    }
    return result;
}

// Version exponentiation rapide (Square & Multiply)
long long powmod_fast(long long a, long long e, long long n) {
    long long result = 1;
    a = a % n;
    while (e > 0) {
        if (e % 2 == 1) {  // Si e est impair
            result = (result * a) % n;
        }
        a = (a * a) % n;
        e = e / 2;
    }
    return result;
}

int main() {
    long long a = 7, e = 123456789, n = 1000000007;

    // Mesure du temps version classique
    clock_t start_classic = clock();
    long long res_classic = powmod_classic(a, e, n);
    clock_t end_classic = clock();
    double time_classic = (double)(end_classic - start_classic) / CLOCKS_PER_SEC;

    // Mesure du temps version rapide
    clock_t start_fast = clock();
    long long res_fast = powmod_fast(a, e, n);
    clock_t end_fast = clock();
    double time_fast = (double)(end_fast - start_fast) / CLOCKS_PER_SEC;

    printf("Résultat classique : %lld, temps = %f s\n", res_classic, time_classic);
    printf("Résultat rapide   : %lld, temps = %f s\n", res_fast, time_fast);

    return 0;
}
