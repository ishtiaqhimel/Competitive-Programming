// source : https://cp-algorithms.web.app/string/string-hashing.html
// https://mathislife.github.io/assets/pdfs/Hashing.pdf
// https://codeforces.com/blog/entry/60445

#include<bits/stdc++.h>
using namespace std;
#define MAX 2000005
#define ll long long

///Hash function: hash(i+1) = (i = 0 to n-1) ((hash(i) * base) + s[i]) mod m
///Hash of a substring: hash(s[i...j]) = (hash(s[0...j]) - (hash(s[0...i-1]) * pow[j-i+1]) + m) mod m

const ll p1 = 737;
const ll p2 = 3079;
const ll m1 = 1e9+7; // 1000000123
const ll m2 = 1e9+9; // 1000000321
vector<ll>p_pow1(MAX), p_pow2(MAX), h1(MAX, 0), h2(MAX, 0);

void Hash(string const& s) {
    int n = s.size();

    p_pow1[0] = 1;
    p_pow2[0] = 1;
    for(int i = 1; i < n; i++) {
        p_pow1[i] = (p_pow1[i-1] * p1) % m1;
        p_pow2[i] = (p_pow2[i-1] * p2) % m2;
    }

    for(int i = 0; i < n; i++) {
        h1[i+1] = ((h1[i] * p1) % m1 + (s[i] - 'a' + 1)) % m1;
        h2[i+1] = ((h2[i] * p2) % m2 + (s[i] - 'a' + 1)) % m2;
    }
}

ll get_Hash(int l, int r) {
    ll val = (h1[r] - (h1[l-1] * p_pow1[r-l+1]) % m1 + m1) % m1;
    return val;
}

int main() {
    string s;
    cin>>s;
    Hash(s);
    int l, r;
    cin>>l>>r;
    cout<<get_Hash(l, r)<<endl;
    return 0;
}
