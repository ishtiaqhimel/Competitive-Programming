/*
  Time Complexity : O(N * sqrt(Q))
  This is always better than O((N+Q) * sqrt(N))
  Source : https://codeforces.com/blog/entry/61203
*/

inline ll gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = (ll)1 << (2*pow - 2);
	ll ans = seg * subSquareSize;
	ll add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query {
    int L, R, id;
    ll ord;

	inline void calcOrder() {
		ord = gilbertOrder(L, R, 21, 0);
	}

    bool operator < (const Query &other) const {
        return ord < other.ord;
    }
} query[N];


// we have to call "query[i].calcOrder();" while taking query input
