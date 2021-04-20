// Sum of all divisors of N approximately in O(sqrt(N)/ln(N)).
// Let, if PF(N) = p1^a1 . p2^a2 … pm^am then SOD(N) = (1+p1+p1^2+p1^3+ … +p1^a1)(1+p2+p2^2+p2^3+ … +p2^a2) ... (1+pm+pm^2+pm^3+ … +pm^am)

ll SOD(ll n) { // with help of sieve
    ll res = 1;
    int sqrtn = sqrt(n);
    for(int i = 0; i < prime.size() && prime[i]<=sqrtn; i++) {
        if(n%prime[i]==0) {
            ll tmp = 1;
            ll p = 1;
            while(n%prime[i]==0) {
                n/=prime[i];
                p*=prime[i];
                tmp+=p;
            }
            sqrtn = sqrt(n);
            res*=tmp;
        }
    }
    if(n!=1) res*=(n+1);
    return res;
}


// SOD from 1 to N in O(sqrt(N)).

ll SOD(ll n) { // source : LOJ 1098
    ll ret = 0;
    for(ll i = 1; i <= sqrt(n); i++) {
        ll j = n / i;
        ret+=(j+i)*(j-i+1LL)/2LL;
        ret+=(j-i)*i;
    }
    return ret;
}
