// Generates all divisors from 1 to N in O(NlogN). (Trial Division)
// It takes almost 2s if N = 10^7 & a number N can have (upper bound) N1/3 divisors

vector<int>d[N];
void divisors() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j+=i) { /// i is j's divisor
            d[j].push_back(i);
        }
    }
}


// Generates all divisors of n in O(sqrt(n)).

vector<ll> Divisors(ll n) {
    vector<ll> v;
    for(ll i = 1; i <= sqrt(n); i++) {
        if(n%i==0) {
            if(n/i == i) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}
