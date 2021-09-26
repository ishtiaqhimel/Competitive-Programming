/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)

#include<bits/stdc++.h>
using namespace std;
#define infLL 1000000000000000000
#define ll long long

/// max(MAX_NODES, MAX_EDGES*cc)+20, cc = 2 if directed, cc = 4 if undirected;
const int N = 1000010;

namespace mcmf {
    ll cap[N], flow[N], cost[N], dis[N];
    int n, m, s, t, Q[N * 10], adj[N], link[N], last[N], from[N], visited[N];

    void init(int nodes) {
        m = 0, n = nodes;
        for(int i = 0; i <= n; i++) last[i] = -1;
    }

    int addEdge(int u, int v, ll c, ll w) {
        adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
        adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
        return (m-2);
    }

    bool spfa() {
        int i, j, x, f = 0, l = 0;
        for(i = 0; i <= n; i++) visited[i] = 0, dis[i] = infLL;

        dis[s] = 0, Q[l++] = s;
        while(f < l) {
            i = Q[f++];
            for(j = last[i]; j != -1; j = link[j]) {
                if(flow[j] < cap[j]) {
                    x = adj[j];
                    if(dis[x] > dis[i] + cost[j]) {
                        dis[x] = dis[i] + cost[j], from[x] = j;
                        if(!visited[x]) {
                            visited[x] = 1;
                            if(f && rand() & 7) Q[--f] = x;
                            else Q[l++] = x;
                        }
                    }
                }
            }
            visited[i] = 0;
        }
        return (dis[t]!=infLL);
    }

    pair<ll, ll> solve(int source, int sink) {
        s = source, t = sink;
        int i, j;
        ll mincost = 0, maxflow = 0;

        while(spfa()) {
            ll aug = infLL;
            for(i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]) {
                aug = min(aug, cap[j] - flow[j]);
            }
            for(i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]) {
                flow[j] += aug, flow[j ^ 1] -= aug;
            }
            maxflow += aug, mincost += aug * dis[t];
        }
        return {mincost, maxflow};
    }
}

int main() {
    int T;
    cin>>T;
    for(int tt = 1; tt <= T; tt++) {
        int n;
        cin>>n;
        mcmf::init(n + 1);
        int s, t, m;
        cin>>s>>t>>m;
        for(int i = 0; i < m; i++) {
            int u, v, c;
            cin>>u>>v>>c;
            mcmf::addEdge(u, v, c, 0);
            mcmf::addEdge(v, u, c, 0);
        }
        cout<<"Case "<<tt<<": "<<mcmf::solve(s, t).second<<endl;
    }

    return  0;
}
