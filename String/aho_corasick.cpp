// Aho-Corasick algorithm
// source : https://returnzerooo.wordpress.com/2017/09/28/%E0%A6%86%E0%A6%B9%E0%A7%8B-%E0%A6%95%E0%A7%8B%E0%A6%B0%E0%A6%BE%E0%A6%B8%E0%A6%BF%E0%A6%95/

const int N = 200005;
const int K = 26;

int node;
int Next[K][N], fail[N], num[N];
bool endMark[N], vis[N];

void init() {
    node = 0;
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            Next[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++) {
        endMark[i] = false;
        vis[i] = false;
        fail[i] = 0;
        num[i] = 0;
    }
}

void Insert(string s) {
    int v = 0;
    for(int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if(!vis[Next[id][v]]) {
            Next[id][v] = ++node;
            vis[node] = true;
        }
        v = Next[id][v];
    }
    endMark[v] = true;
}

void build_fail() {
    queue<int>q;

    for(int i = 0; i < K; i++) {
        if(vis[Next[i][0]]) {
            q.push(Next[i][0]); // root's child
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < K; i++) {
            int v = Next[i][u];
            if(!vis[v]) continue;
            q.push(v);
            int p = fail[u];
            while(p && vis[Next[i][p]]==0) {
                p = fail[p];
            }
            fail[v] = Next[i][p];
        }
    }
}

void Search(string s) {
    int v = 0;
    for(int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        while(v && !vis[Next[id][v]]) {
            v = fail[v];
        }
        v = Next[id][v];
        int tmp = v;
        while(tmp) {
            num[tmp]++;
            tmp = fail[tmp];
        }
    }
}

int main() {
    init(); 

    string s;
    cin>>s;
    
    int n;
    cin>>n;
    while(n--) {
        string a;
        cin>>a;
        Insert(a);
    }
    build_fail();
    Search(s);
    for(int i = 0; i <= node; i++) {
        if(endMark[i]) {
            cout<<num[i]<<endl; // number of occurance of a word
        }
    }
    
    return 0;
}
