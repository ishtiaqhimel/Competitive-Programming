/*
 isprime(ull n) -> check if n is a prime or not in K * log(n)
 pollard(ll n) -> return the smallest prime factor of n
 brent(ll n) -> do same as pollard
 dfs(ll n, vector<int>&v) -> store prime factors of n in vector v
 time complexity is O(n^(1/4))
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define ull unsigned ll
#define ulll unsigned lll

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

ull pow(ull a, ull t, ull mod) {
    ull r = 1;
    for(; t; t >>= 1, a = (ulll)a * a % mod) if(t & 1) r = (ulll)r * a % mod; return r;
}

bool isprime(ull n) {
    if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
    s = __builtin_ctzll(n - 1), d = n >> s;
    for(ull a : A) {
        ull p = pow(a % n, d, n), i = s;
        while(p != 1 && p != n - 1 && a % n && i--) p = (ulll)p * p % n;
        if(p != n - 1 && i != s) return 0;
    }
    return 1;
}

ll pollard(ll n) {
    if(n == 1) return n;
    if(n % 2 == 0) return 2;
    ll x = (rng() % (n - 2)) + 2, y = x, c = (rng() % (n - 1)) + 1, d = 1;
    while(d == 1) {
        x = ((ulll)x * x + c) % n;
        y = ((ulll)y * y + c) % n;
        y = ((ulll)y * y + c) % n;
        d = __gcd(abs(x - y), n);
        if(d == n) return pollard(n);
    }
    return d;
}

ll brent(ll n) {
    if(n%2==0) return 2;
    ll y = rng() % (n-1) + 1;
    ll c = rng() % (n-1) + 1;
    ll m = rng() % (n-1) + 1;
    ll g = 1, r = 1, q = 1, ys, x;
    while(g==1) {
        x = y;
        for(int i = 0; i<r; i++) y = ((ulll)y * y + c) % n;
        ll k = 0;
        while( k<r && g==1 ) {
            ys = y;
            for(int i = 0; i<min(m, r-k); i++) {
                y = ((ulll)y * y + c) % n;
                q = ((ulll)q * abs(x-y)) % n;
            } g = __gcd(q, n); k = k + m;
        } r *= 2;
    }
    if(g==n) {
        while(true) {
            ys = ((ulll)ys * ys + c) % n;
            g = __gcd(abs(x-ys), n);
            if(g > 1) break;
        }
    }
    return g;
}

void dfs(ll n, vector<int>&v) {
    if(n==1) return;
    if(isprime(n)) {
        v.push_back(n);
    }
    else {
        ll d=brent(n);
        dfs(d, v);
        dfs(n/d, v);
    }
}

int main() {
    ll n; cin>>n;
    vector<int>v;
    dfs(n, v); 
    for(auto x : v) cout<<x<<" ";
    return 0;
}
