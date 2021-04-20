// need to call sieve first

vector<ll> seg_sieve(ll a, ll b) {
    vector<ll>ans;
    bool Check[b-a+1];
    memset(Check, 0, sizeof(Check));
  
    if(a==1) a++;
    for(int i = 0; i < prime.size() && prime[i] <= sqrt(b); i++) {
        ll j = prime[i] * prime[i];
        if(j < a)
            j = ((a + prime[i] -1)/prime[i]) * prime[i];
        for( ; j <= b; j+=prime[i])
            Check[j-a] = 1; /// not prime
    }
    for(int i = 0; i <= b-a; i++)
        if(!Check[i]) ans.push_back(a+i);
    return ans;
}
