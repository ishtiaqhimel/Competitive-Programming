// Build in : O(nlogn), Query in : O(1)

#include<bits/stdc++.h>
using namespace std;
#define N 100005

int a[N], sparse[25][N];

void Sparse_Table(int n) {
    for(int i = 0; i < n; i++) sparse[0][i] = i;

    for(int i = 1; (1<<i) < n; i++) {
        for(int j = 0; j+(1<<i-1) < n; j++) {
            int x = sparse[i-1][j];
            int y = sparse[i-1][j+(1<<i-1)];
            sparse[i][j] = (a[x]<=a[y])?x:y;
        }
    }
}

int RMQ(int l, int r) {
    int k = log2(r-l);
    int x = sparse[k][l];
    int y = sparse[k][r-(1<<k)+1];
    return (a[x]<=a[y])?x:y;
}

int main()
{
    int n, q;
    cin>>n>>q;
    for(int i = 0; i < n; i++) cin>>a[i];
    Sparse_Table(n);
    while(q--) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        cout<<a[RMQ(l,r)]<<endl;
    }
    return 0;
}
