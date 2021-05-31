// O(nlogn)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

ll Tree[N];

ll query(int idx) {
    ll sum = 0;
    while(idx>0) {
        sum+=Tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

///n is the size of the array, x is the number to add
void update(int idx, ll x, int n) {
    while(idx<=n) {
        Tree[idx]+=x;
        idx+=idx&(-idx);
    }
}

///actual value of a position after update
int readSingle(int idx) {
    int sum = Tree[idx];
    if(idx > 0) {
        int z = idx - (idx & (-idx));
        idx--;
        while(idx!=z) {
            sum-=Tree[idx];
            idx-=(idx & (-idx));
        }
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    // must be 1 indexed
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i], n);
    }

    update(3, 5, n);
    cout << query(3) << endl;
    update(1, 1, n);
    cout << query(n) << endl;
    cout<<readSingle(3)<<endl;
    return 0;
}
