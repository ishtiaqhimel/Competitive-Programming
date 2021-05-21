/*
  Find smallest x where, 
  x = r1 (mod m1)
  x = r2 (mod m2)
  ...
  x = rn (mod mn)
  
  Time Complexity : O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll exgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while(b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

pair<ll, ll> CRT(vector<ll>r, vector<ll>m) {
    int n = r.size();
    if(n==0) return {-1, -1};
    ll a1 = r[0];
    ll m1 = m[0];
    a1 = a1 % m1;
    for(int i = 1; i < n; i++) {
        ll a2 = r[i];
        ll m2 = m[i];
        ll g = __gcd(m1, m2);
        if(a1%g != a2%g) return {-1, -1};
        ll p, q;
        g = exgcd(m1/g, m2/g, p, q);
        ll mod = m1 / g * m2;
        ll x = ((__int128)a1 * (m2/g) % mod * q % mod + (__int128)a2 * (m1/g) % mod * p % mod) % mod;
        a1 = x;
        if(a1 < 0) a1 += mod;
        m1 = mod;
    }
    return {a1, m1};
}

int main() {
    int n;
    cin>>n;
    vector<ll>r(n), m(n);
    for(int i = 0; i < n; i++) cin>>r[i];
    for(int i = 0; i < n; i++) cin>>m[i];
    pair<ll, ll> p = CRT(r, m);
    cout<<p.first<<" "<<p.second<<endl;
    
    return 0;
}
