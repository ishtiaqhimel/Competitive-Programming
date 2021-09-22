/// O(EV^2)
#include<bits/stdc++.h>
using namespace std;
#define infLL 2000000000000000000
#define ll long long

const int N = 5000;

struct Dinic {
    struct edge {
        int to, rev;
        ll flow, w;
        int id;
    };

    int n, s, t, mxid;
    vector<int> d, flow_through;
    vector<int> done;
    vector<vector<edge> > g;

    Dinic() {}

    Dinic(int _n) {
        n = _n + 10;
        mxid = 0;
        g.resize(n);
    }

    void add_edge(int u, int v, ll w, int id = -1) {
        edge a = {v, (int)g[v].size(), 0, w, id};
        edge b = {u, (int)g[u].size(), 0, 0, -2}; //for bidirectional edges cap(b) = w
        g[u].emplace_back(a);
        g[v].emplace_back(b);
        mxid = max(mxid, id);
    }

    bool bfs() {
        d.assign(n, -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &e : g[u]) {
                int v = e.to;
                if(d[v]==-1 && e.flow < e.w) d[v] = d[u] + 1, q.push(v);
            }
        }
        return d[t]!=-1;
    }

    ll dfs(int u, ll flow) {
        if(u==t) return flow;
        for(int &i = done[u]; i < (int)g[u].size(); i++) {
            edge &e = g[u][i];
            if(e.w <= e.flow) continue;
            int v = e.to;
            if(d[v]==d[u]+1) {
                ll nw = dfs(v, min(flow, e.w - e.flow));
                if(nw > 0) {
                    e.flow += nw;
                    g[v][e.rev].flow -= nw;
                    return nw;
                }
            }
        }
        return 0;
    }

    ll max_flow(int _s, int _t) {
        s = _s;
        t = _t;
        ll flow = 0;
        while(bfs()) {
            done.assign(n, 0);
            while(ll nw = dfs(s, infLL)) flow += nw;
        }
        flow_through.assign(mxid + 10, 0);
        for(int i = 0; i < n; i++) for(auto e: g[i]) if(e.id >= 0) flow_through[e.id] = e.flow;
        return flow;
    }
};

int main() {
    int n, m;
    cin>>n>>m;
    Dinic F(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        F.add_edge(u, v, w);
    }
    cout<<F.max_flow(1, n)<<endl;

    return  0;
}
