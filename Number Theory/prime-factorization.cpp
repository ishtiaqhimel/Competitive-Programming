// A number N can have utmost log10(N) prime divisors. Generates all prime factors approximately in O(sqrt(N)/ln(N)

void primeFactors(int n) { ///with help of sieve
    int sqrtn = sqrt(n);
    for(int i = 0; i < prime.size() && prime[i]<=sqrtn; i++) {
        if(n%prime[i]==0) {
            while(!(n%prime[i])) {
                n/=prime[i];
                cout<<prime[i]<<" ";
            }
            sqrtn = sqrt(n);
        }
    }
    if(n!=1) cout<<n<<endl;
}
