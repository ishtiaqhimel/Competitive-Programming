ll a[N];
ll Tree[N*4];

void init(int node, int b, int e) {
    if(b == e) {
        Tree[node] = a[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    Tree[node] = Tree[Left] + Tree[Right];
}

ll query(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return Tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, ll newvalue) {
    if(i > e || i < b) return;
    if(b >= i && e <= i) {
        Tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    Tree[node] = Tree[Left] + Tree[Right];
}
