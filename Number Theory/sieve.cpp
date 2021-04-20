// To generate all primes up to N in O(nlogn). Number of Primes up to N is N/ln(N).

bool vis[N];
vector<int>prime;

void sieve() {
    memset(vis, 0, sizeof(vis));
    vis[0] = vis[1] = 1;
  
    for(int i = 3; i * i <= N; i+=2) { // didn't check even numbers
        if(vis[i]==0) {
            for(int j = i * i; j < N; j+=(2*i)) {
                vis[j] = 1;
            }
        }
    }
  
    prime.push_back(2);
    for(int i = 3; i < N; i+=2) {
        if(vis[i]==0) prime.push_back(i);
    }
}
