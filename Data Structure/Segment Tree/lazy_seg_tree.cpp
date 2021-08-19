// query(l, r) = sum of segment l to r-1
// update(l, r, v) = assign v to all elements in segment l to r-1

ll Tree[N * 4], Lazy[N * 4];
 
void push(int node, int b, int e) {
    if(Lazy[node]==0) return;
    int Left = 2 * node;
    int Right = 2 * node + 1;
    int mid = (b + e) / 2;
    Tree[Left] = (Lazy[node] * (ll)(mid - b + 1LL));
    Tree[Right] = (Lazy[node] * (ll)(e - (mid + 1LL) + 1LL));
    Lazy[Left] = Lazy[node];
    Lazy[Right] = Lazy[node];
    Lazy[node] = 0;
}

ll query(int node, int b, int e, int i, int j) {
    if(b > j || e < i) return 0LL;
    if(b >= i && e <= j) return Tree[node];
    push(node, b, e);
    int Left = 2 * node;
    int Right = 2 * node + 1;
    int mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
 
void update(int node, int b, int e, int i, int j, ll v) {
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
        Tree[node] = (v * (ll)(e - b + 1));
        Lazy[node] = v;
        return;
    }
    push(node, b, e);
    int Left = 2 * node;
    int Right = 2 * node + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, v);
    update(Right, mid + 1, e, i, j, v);
    Tree[node] = Tree[Left] + Tree[Right];
}
