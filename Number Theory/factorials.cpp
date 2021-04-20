// 1. Number of digits in a Factorial (In different bases):

int factorialDigit(int n, int base) {
    double x = 0;
    for(int i = 1; i <= n; i++) x+=(log10(i)/log10(base));
    int res = x + 1 + eps;
    return res;
}


// 2. Leading K digits of a Factorial:

int leadingDigitFact(int n, int k) {
    double fact = 0;
    for(int i = 1; i <= n; i++) fact+=log10(i);
    double q = fact - floor(fact+eps);
    double B = pow(10, q);
    for(int i = 0; i < k-1; i++) B*=10;
    return floor(B+eps);
}

// 3. Prime Factorization of a Factorial:

void factFactorize(int n) { // with the help of sieve
    for(int i = 0; i < prime.size() && prime[i] <= n; i++) {
        int x = n;
        int freq = 0;
        while(x/prime[i]) {
            freq+=(x/prime[i]);
            x = x / prime[i];
        }
        printf("%d ^ %d\n", prime[i], freq);
    }
}

/* N.B: For trailing zeros we have to find power of 2 & 5 as 10 = 2^1 * 5^1. Then the minimum of them is the result. We can also find it in any other base. */
