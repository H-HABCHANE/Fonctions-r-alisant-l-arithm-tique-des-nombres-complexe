#include <stdio.h>
#include <math.h>

typedef struct {
    float re;
    float im; 
} Complex;

Complex add(Complex z1, Complex z2) {
    Complex result;
    result.re = z1.re + z2.re;
    result.im = z1.im + z2.im;
    return result;
}

Complex sous(Complex z1, Complex z2) {
    Complex result;
    result.re = z1.re - z2.re;
    result.im = z1.im - z2.im;
    return result;
}

Complex opp(Complex z) {
    Complex result;
    result.re = -z.re;
    result.im = -z.im;
    return result;
}

Complex mult(Complex z1, Complex z2) {
    Complex result;
    result.re = z1.re * z2.re - z1.im * z2.im;
    result.im = z1.im * z2.re + z1.re * z2.im;
    return result;
}

Complex div(Complex z1, Complex z2) {
    Complex result;
    float denom = z2.re * z2.re + z2.im * z2.im;
    result.re = (z1.re * z2.re + z1.im * z2.im) / denom;
    result.im = (z1.im * z2.re - z1.re * z2.im) / denom;
    return result;
}

float module(Complex z1) {
    return sqrt(z1.re * z1.re + z1.im * z1.im);
}

Complex inverse(Complex z1) {
    Complex result;
    float denom = z1.re * z1.re + z1.im * z1.im;
    result.re = z1.re / denom;
    result.im = -z1.im / denom;
    return result;
}

Complex puissance(Complex z, int n) {
    Complex result;
    result.re = 1;
    result.im = 0;

    for (int i = 0; i < n; i++) {
        result = mult(result, z);
    }

    return result;
}


int main() {
    Complex z1, z2, sum, multip, soust, oppose, inver, division , power ;
    float mod;
      
    z1.re = 2;
    z1.im = 3;

    z2.re = 4;
    z2.im = 5;

    sum = add(z1, z2);
    soust = sous(z1, z2);
    multip = mult(z1, z2);
    oppose = opp(z1);
    mod = module(z1);
    inver = inverse(z1);
    division = div(z1, z2);
    power = puissance(z1, 3);

    printf("z1^3 = %f + %fi\n", power.re, power.im);
    printf("Opposé = %f + %fi\n", oppose.re, oppose.im);
    printf("Somme = %f + %fi\n", sum.re, sum.im);
    printf("Multiplication = %f + %fi\n", multip.re, multip.im);
    printf("Soustraction = %f + %fi\n", soust.re, soust.im);
    printf("Module = %f\n", mod);
    printf("Inverse = %f + %fi\n", inver.re, inver.im);
    printf("Division = %f + %fi\n", division.re, division.im);

    return 0;
}

