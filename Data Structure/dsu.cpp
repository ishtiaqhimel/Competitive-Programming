#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int parent[N], Rank[N];

void opt() {
    for(int i = 1; i < N; i++) {
        parent[i] = i;
        Rank[i] = 0;
    }
}

int find_parent(int x) {
    if(parent[x]==x) return x;
    return parent[x] = find_parent(parent[x]);
}

void make_union(int x, int y) {
    parent[find_parent(x)] = find_parent(y);
    /*

    x = find_parent(x);
    y = find_parent(y);
    if(x!=y)
    {
        if(Rank[x] > Rank[y])
            swap(x,y);
        parent[x] = y;

        Rank[y]+=Rank[x]; ///union by size

        if(Rank[x]==Rank[y]) ///union by rank based on the depth of the trees
            Rank[y]++;
    }

    */
}

bool isUnion(int x, int y) {
    return find_parent(x) == find_parent(y);
}

int main() {
    opt();
    int n, q;
    cin>>n>>q;
    while(n--) {
        int a, b;
        cin>>a>>b;
        make_union(a,b);
    }
    while(q--) {
        int c, d;
        cin>>c>>d;
        if(isUnion(c,d)==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
