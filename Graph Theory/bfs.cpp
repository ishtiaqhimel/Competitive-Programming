///searching algorithm on graphs by BFS
///Complexity O(n+m)

/*
    Application:
    -----------
    1. Find the shortest path from a source to other vertex(v) in an unweighted graph.
        if(!vis[v])
            cout<<"No Path"<<endl;
        else
        {
            vector<int>path;
            for(int u = v; u!=-1; u = Parent[u])
                path.push_back(u);
            reverse(path.begin(), path.end());
        }
    2. Find all connected components in undirected graph.
    3. 0-1 BFS in O(E):
        Edge having weight 0/1. Use deque<int>Q and push_back for 1 else push_front
        (N.B. If weight is very small(<16) we can use dial algo in O(E+WV))
    4.Finding the shortest cycle in a directed unweighted graph.
    5. Find all the edges that lie on any shortest path between a given pair of vertices (a,b)
        Let, da[] -> shortest distance from a
             db[] -> shortest distance from b
        now the edge (u,v) lies on if da[u]+1+db[v] = da[b]
    6. Find all the vertices on any shortest path between a given pair of vertices (a,b).
        da[u]+db[u] = da[b];
    7. Find the shortest path of even length from a source vertex s to a target vertex t in
    an unweighted graph.
    (u, c) -> u - current node & c - parity of that node from source
*/

#include<bits/stdc++.h>
using namespace std;
#define N 100005

vector<int>edge[N];
bool vis[N];
int Level[N], Parent[N];

void bfs(int source) {
    queue<int>Q;
    Q.push(source);
    vis[source] = true;
    Level[source] = 0; // Leveling from 0
    Parent[source] = -1; // root
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
      
        for(auto v : edge[u]) {
            if(!vis[v]) {
                vis[v] = true;
                Q.push(v);
                Level[v] = Level[u] + 1;
                Parent[v] = u;
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int u, v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    bfs(1);

    return 0;
}
