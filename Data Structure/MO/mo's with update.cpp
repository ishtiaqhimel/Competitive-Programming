/*
  Time Complexity O(Q * N^(2/3))
  Problem : https://www.spoj.com/problems/XXXXXXXX/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 50005;
const int Q = 100005;

int a[N], last[N], rev[N+Q], cnt[N+Q];
bool use[N];

struct Query {
    int idx, l, r, t, lb, rb;
    bool operator < (const Query &other) const {
        return (lb < other.lb) || (lb==other.lb && rb < other.rb) || (lb==other.lb && rb==other.rb && t < other.t); 
    }
} q[Q];

struct update {
    int idx, new_y, prv_y;
} u[Q];

int nq, nu, compressed_val;

ll ans[Q], curr_ans;

void add(int pos) {
    use[pos] = true;
    if(++cnt[a[pos]]==1) {
        curr_ans += rev[a[pos]];
    }
}

void del(int pos) {
    use[pos] = false;
    if(--cnt[a[pos]]==0) {
        curr_ans -= rev[a[pos]];
    }
}

void reflect_update(int pos, int val) {
    if(!use[pos]) {
        a[pos] = val;
        return;
    }
    del(pos);
    a[pos] = val;
    add(pos);
}

void do_update(int i) { reflect_update(u[i].idx, u[i].new_y); }
void undo_update(int i) { reflect_update(u[i].idx, u[i].prv_y); }

int main()
{
    int n;
    scanf("%d", &n);
    int block = pow(n, 2.0/3.0);
    map<int, int>mp;
    for(int i = 1; i<= n; i++) {
        scanf("%d", a+i);
        last[i] = a[i];
        mp[a[i]];
    }
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        char ch;
        int x, y;
        getchar();
        scanf("%c %d %d", &ch, &x, &y);
        if(ch=='Q') {
            nq++;
            q[nq] = {nq, x, y, nu, x / block, y / block};
        }
        else {
            u[++nu] = {x, y, last[x]};
            last[x] = y;
            mp[y];
        }
    }
    // Coordinate compression
    for(auto &it : mp) {
        it.second = ++compressed_val;
        rev[compressed_val] = it.first;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
    }
    for(int i = 1; i <= nu; i++) {
        u[i].new_y = mp[u[i].new_y];
        u[i].prv_y = mp[u[i].prv_y];
    }
    // Sort the queries
    sort(q, q+nq);
    // Answer the queries
    for(int i = 1, T = 0, L = 1, R = 0; i <= nq; i++) {
        while(T < q[i].t) do_update(++T);
        while(T > q[i].t) undo_update(T--);
        while(R < q[i].r) add(++R);
        while(L > q[i].l) add(--L);
        while(R > q[i].r) del(R--);
        while(L < q[i].l) del(L++);
        ans[q[i].idx] = curr_ans;
    }
    for(int i = 1; i <= nq; i++) printf("%lld\n", ans[i]);
    
    return 0;
}
