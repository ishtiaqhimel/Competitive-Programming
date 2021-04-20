inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

// For string :

pair<string, ll> Solve(string a, ll b) {
    string res;
    ll rem = 0;
    bool flag = false;
    for(int i = 0; i < a.size(); i++) {
        rem = (rem * 10 + (a[i]-'0'));
        if(rem < b && !flag) continue;
        int num = rem / b;
        res+=('0'+num);
        flag = true;
        rem = rem % b;
    }
    return {res, rem};
}
