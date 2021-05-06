// Offline query in O((n+q)*sqrt(n))

int K, ans[N], a[N], sum;

struct Query {
    int L, R, id;
    bool operator < (const Query &other) const {
        int block_own = L / K;
        int block_other = other.L / K;
        if(block_own==block_other) return ((block_own & 1)? R < other.R : R > other.R);
        return block_own < block_other;
    }
} query[N];

void add(int index) {
    sum += a[index];
}

void del(int index) {
    sum -= a[index];
}

int main()
{
    int n, q;
    cin>>n>>q;
    K = sqrt(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < q; i++) {
        cin>>query[i].L>>query[i].R;
        query[i].id = i;
    }
    sort(query, query+q);
    int l = 0, r = -1;
    for(int i = 0; i < q; i++) {
        while(l > query[i].L) add(--l);
        while(r < query[i].R) add(++r);
        while(l < query[i].L) del(l++);
        while(r > query[i].R) del(r--);
        ans[query[i].id] = sum;
    }
    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
    
    return 0;
}
