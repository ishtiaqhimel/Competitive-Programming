/*
  Time Complexity : O(n * n * m)
  
  - Find the maximum matching of the minimum weight in it.
  - Find the maximum matching of the maximum weight in it. (all weights must be multiplied by minus one, replace all minimums with maxima, and infinities with minus infinity)
  -  A matrix is given a[1...n][1...m]. It is required to find two arrays u[1...n] and v[1...m] such that for any i and j is satisfied u[i] + v[j] <= a[i][j], but the sum of the elements of the arrays u[] and v[] is maximum.
*/

#include<bits/stdc++.h>
using namespace std;
#define inf 2000000000
#define N 300

int n, m;
int cost[N][N], res[N];

int hungarian() {
    vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    for(int i = 1; i <= n; i++) {
        p[0] = i;
        int j0 = 0;
        vector<int>minv(m + 1, inf);
        vector<bool>used(m + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], delta = inf, j1 = -1;
            for(int j = 1; j <= m; j++) {
                if(!used[j]) {
                    int cur = cost[i0][j] - u[i0] - v[j];
                    if(cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if(minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for(int j = 0; j <= m; j++) {
                if(used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                }
                else minv[j] -= delta;
            }
            j0 = j1;
        } while(p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }
    // storing matching
    for(int i = 1; i <= m; i++) res[p[i]] = i;

    return -v[0];
}

int main() {
    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>>cost[i][j];
        }
    }
    cout<<hungarian()<<endl;
  
    for(int i = 1; i <= m; i++) cout<<res[i]<<" ";

    return 0;
}
