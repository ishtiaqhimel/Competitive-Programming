// Count the number of divisors of N approximately in O(sqrt(N)/ln(N)).
// Let, if PF(N) = p1^a1.p2^a2… pm^am then NOD(N) = (a1 + 1)(a2 + 1) … (am + 1).

ll NOD(ll n) { // with help of sieve
    ll res = 1;
    int sqrtn = sqrt(n);
    for(int i = 0; i < prime.size() && prime[i] <= sqrtn; i++) {
        if(n%prime[i]==0) {
            ll p = 0; ///power of prime
            while(n%prime[i]==0) {
                n/=prime[i];
                p++;
            }
            sqrtn = sqrt(n);
            p++;
            res*=p;
        }
    }
    if(n > 1) res*=2LL;
    return res;
}


// NOD from 1 to N in O(sqrt(N))

int NOD(int n) {
    int res = 0;
    int u = sqrt(n);
    for(int i = 1; i <= u; i++) res+=(n/i)-i;
    res*=2;
    res+=u;
    return res;
}

// Source : https://forthright48.com/divisor-summatory-function/
