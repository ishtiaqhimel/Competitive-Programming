/*
    Tree to Prufer Code
    Time Complexity : O(n)
    Properties :
    (i) If a node has degree d, then that node will appear in prufer code exactly d−1 times.
    (ii) Leaves never appear in Prufer Code.
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
vector<int>edge[N], parent;

void dfs(int u) {
    for(auto v : edge[u]) {
        if(v != parent[u]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

vector<int> prufer_code() {
    parent.resize(n + 1);
    parent[n] = -1;
    dfs(n);

    int ptr = -1;
    vector<int>degree(n + 1);
    for(int i = 0; i < n; i++) {
        degree[i + 1] = edge[i + 1].size();
        if(degree[i + 1]==1 && ptr==-1) ptr = i + 1;
    }
    vector<int>code(n-2);
    int leaf = ptr;
    for(int i = 0; i < n - 2; i++) {
        int nxt = parent[leaf];
        code[i] = nxt;
        if(--degree[nxt]==1 && nxt < ptr) {
            leaf = nxt;
        }
        else {
            ptr++;
            while(degree[ptr]!=1) ptr++;
            leaf = ptr;
        }
    }
    return code;
}

int main() {
    cin>>n;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<int> v = prufer_code();
    for(auto x : v) cout<<x<<" ";
    
    return 0;
}
