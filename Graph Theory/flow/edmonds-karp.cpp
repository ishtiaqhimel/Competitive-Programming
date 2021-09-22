/// O(VE^2)
#include<bits/stdc++.h>
using namespace std;
#define infLL 2000000000000000000
#define ll long long

const int N = 2000;

int n, m;
vector<int>edge[N];
ll capacity[N][N];

ll bfs(int s, int t, vector<int> &parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    using pii = pair<int, ll>;
    queue<pii>q;
    q.push({s, infLL});
    while(!q.empty()) {
        int u = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for(int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i];
            
            if(parent[v]==-1 && capacity[u][v]) {
                parent[v] = u;
                ll newFlow = min(flow, capacity[u][v]);
                if(v==t) return newFlow;
                q.push({v, newFlow});
            }
        }
    }
    return 0;
}

ll maxFlow(int s, int t) {
    ll flow = 0;
    vector<int>parent(n+1);
    ll newFlow;
    while(newFlow=bfs(s, t, parent)) {
        flow += newFlow;
        int v = t;
        while(v!=s) {
            int u = parent[v];
            capacity[u][v] -= newFlow;
            capacity[v][u] += newFlow;
            v = u; 
        }
    }
    return flow;
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        capacity[u][v] = w;
        capacity[v][u] = w;
    }
    int s, t;
    cin>>s>>t; /// source(s) & sink(t)
    ll ans = maxFlow(s, t);
    cout<<ans<<endl;

    return  0;
}
