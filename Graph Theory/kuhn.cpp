/*
Maximum Bipartite Matching
Time Complexity O(VE)

Maximum Independent Set in Bipartite Graphs : https://ali-ibrahim137.github.io/competitive/programming/2020/01/02/maximum-independent-set-in-bipartite-graphs.html

Minimum Path Cover on a DAG : https://towardsdatascience.com/solving-minimum-path-cover-on-a-dag-21b16ca11ac0
*/

#include<bits/stdc++.h>
using namespace std;
#define N 1000

int Left[N], Right[N], vis[N];
vector<int>edge[N];
int n, m;

bool Kuhn(int u) {
    for(int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        if(vis[v]) continue;
        vis[v] = 1;
        if(Right[v]==-1 || Kuhn(Right[v])) {
            Right[v] = u;
            Left[u] = v;
            return true;
        }
    }
    return false;
}

int BM() {
    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if(Kuhn(i)) cnt++;
    }

    return cnt;
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        edge[u].push_back(v);
    }
    cout<<BM()<<endl;

    return 0;
}
