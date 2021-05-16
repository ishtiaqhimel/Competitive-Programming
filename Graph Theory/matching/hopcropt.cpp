/*
  Maximum Bipartite Matching
  Time Complexity O(E * sqrt(V))
*/

int match[N], dist[N];
bool vis[N];
vector<int>edge[N];

bool bfs(int n) {
    queue<int>q;
    for(int i = 1; i <= n; i++) {
        if(match[i]==0) {
            dist[i] = 0;
            q.push(i);
        }
        else dist[i] = inf;
    }
    dist[0] = inf;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u) {
            for(int i = 0; i < edge[u].size(); i++) {
                int v = edge[u][i];
                if(dist[match[v]]==inf) {
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                }
            }
        }
    }
    return (dist[0]!=inf);
}

bool dfs(int u) {
    if(u) {
        for(int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i];
            if(dist[match[v]]==dist[u]+1 && dfs(match[v])) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        dist[u] = inf;
        return 0;
    }
    return true;
}

int hopcropt(int n) {
    int cnt = 0;
    while(bfs(n)) {
        for(int i = 1; i <= n; i++) {
            if(match[i]==0 && dfs(i)) cnt++;
        }
    }
    return cnt;
}
