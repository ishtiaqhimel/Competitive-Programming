#include<bits/stdc++.h>
using namespace std;

struct node {
    node* next[27];
    bool endmark;
    node() {
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        endmark = false;
    }
};

node* root;

void Insert(string s) {
    node* curr = root;
    for(int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if(curr->next[id]==NULL) {
            curr->next[id] = new node();
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool Search(string s) {
    node* curr = root;
    for(int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if(curr->next[id]==NULL) {
            return false;
        }
        curr = curr->next[id];
    }
    return curr->endmark;
}

bool isEmpty(node* curr) {
    for(int i = 0; i < 26; i++) {
        if(curr->next[i]) return false;
    }
    return true;
}

void Delete(node* curr) {
    for(int i = 0; i < 26; i++) {
        if(curr->next[i]) {
            Delete(curr->next[i]);
        }
    }
    delete(curr);
}

int main() {
    root = new node();
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        Insert(s);
    }
    int q;
    cin>>q;
    while(q--) {
        string s;
        cin>>s;
        if(Search(s)) {
            cout<<"Found"<<endl;
        }
        else {
            cout<<"Not Found"<<endl;
        }
    }
    Delete(root); /// RIP Trie...

    return 0;
}
