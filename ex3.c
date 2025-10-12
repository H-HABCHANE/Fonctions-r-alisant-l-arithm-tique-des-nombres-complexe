#include <stdio.h>

int hammingWeight(int n) {
    int count = 0;
    while (n != 0) {
        if (n & 1)  // si le bit de poids faible vaut 1
            count++;
        n >>= 1;    // décalage à droite
    }
    return count;
}

int main() {
    int n;
    printf("Entrez un entier : ");
    scanf("%d", &n);
    printf("Le poids de Hamming de %d est : %d\n", n, hammingWeight(n));
    return 0;
}
