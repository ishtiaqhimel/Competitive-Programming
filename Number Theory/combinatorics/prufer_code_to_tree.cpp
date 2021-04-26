/*
    Prufer Code to Tree
    Time Complexity : O(n)
    Applications : 
    (i) Every Sequence of n-2 numbers in the range [1;n] corresponds to a tree.
    (ii) The number of spanning trees we can build with n labeled node is n^(n-2). [cayley's formula]
    (iii) Number of ways to make a graph connected : 
        https://cp-algorithms.com/graph/pruefer_code.html#toc-tgt-8
    (iv) Building Tree from Degree Count :
        https://forthright48.com/application-of-prufer-code-random-tree-generation-cayleys-formula-and-building-tree-from-degree-count/
    
    Prufer Code allows to create a lot more general formulas than these...
*/

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

vector<pii> prufer_decode(vector<int> const& code) {
    int n = code.size() + 2;
    vector<int>degree(n, 1);
    for(auto i : code) degree[i]++;

    int ptr = 1;
    while(degree[ptr] != 1) ptr++;
    int leaf = ptr;
    
    vector<pii>edges;
    for(auto v : code) {
        edges.emplace_back(leaf, v);
        if(--degree[v]==1 && v < ptr) {
            leaf = v;
        }
        else {
            ptr++;
            while(degree[ptr]!=1) ptr++;
            leaf = ptr;
        }
    }
    edges.emplace_back(leaf, n);
    return edges;
}

int main() {
    int n;
    cin>>n;
    vector<int>code(n);
    for(int i = 0; i < n; i++) cin>>code[i];
    vector<pii> v = prufer_decode(code);
    for(auto x : v) cout<<x.first<<" "<<x.second<<endl;

    return 0;
}
