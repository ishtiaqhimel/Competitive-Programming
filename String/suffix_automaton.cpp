// O(n)
// source : https://cp-algorithms.web.app/string/suffix-automaton.html

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;

struct state {
    int len, link;
    map<char, int> Next;
};

state st[3 * N];
int sz, last;

void init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 0;
    last = 0;
}

void SA_Extend(char ch) {
    int curr = ++sz;
    st[curr].len = st[last].len + 1;
    int p = last;
    while(p!=-1 && !st[p].Next.count(ch)) {
        st[p].Next[ch] = curr;
        p = st[p].link;
    }
    if(p==-1) {
        st[curr].link = 0;
    }
    else {
        int q = st[p].Next[ch];
        if(st[p].len + 1==st[q].len) {
            st[curr].link = q;
        }
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].Next = st[q].Next;
            st[clone].link = st[q].link;
            while(p!=-1 && st[p].Next[ch]==q) {
                st[p].Next[ch] = clone;
                p = st[p].link;
            }
            st[q].link = st[curr].link = clone;
        }
    }
    last = curr;
}

int main() {
    init();
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++) SA_Extend(s[i]);
    
    return 0;
}
