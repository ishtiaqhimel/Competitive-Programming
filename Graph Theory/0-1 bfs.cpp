// O(E + V)
/*
    
    1. Can we apply the same trick if our edge weights can only be 0 and x (x >= 0) ?
      - Yes.
    2. Can we apply the same trick if our edge weights are x and x+1 (x >= 0) ?
      - No.
    3. Can we apply the same trick if our edge weights are x and y (x,y >= 0) ?
      - No.

*/

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define inf 2000000000

const int N = 10001;

vector<pii>edge[N];

int bfs(int source, int destination) {
    vector<int>d(destination, inf);
    d[source] = 0;
    deque<int>q;
    q.push_front(source);
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(auto V : edge[u]) {
            int v = V.first;
            int w = V.second;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if(w==1) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    return d[destination];
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin>>u>>v>>c;
        edge[u].push_back({v, c});
        edge[v].push_back({u, c});
    }
    cout<<bfs(1, n)<<endl;
    
    return 0;
}
