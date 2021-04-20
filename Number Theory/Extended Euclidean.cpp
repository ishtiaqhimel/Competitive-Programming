// We will get the value of (x, y) and gcd(a,b) for ax + by = gcd(a,b) in O(log(min(a,b))).
// Gives the minimum result for |x| + |y| and for multiple such results give the one having x <= y.

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
