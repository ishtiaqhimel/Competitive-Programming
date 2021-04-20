/* phi(n) : number of gcd(i, n) = 1 where i = 1 to n-1.
Properties :
-----------
1. Number of elements e, such that gcd(e, n) = d is equal to phi(n/d).
2. N = sum(phi(d)) where d are divisors of N
3. For n > 2, phi(n) is always even.
4. Sum of integers that are co-prime to n equals to (phi(n)/2)*n.
5. If n is prime, phi(n) = n-1 & phi(n^k) = n^k - n^(k-1).
6. phi() is Multiplicative, phi(n*m) = phi(n) * phi(m) where n & m are co-prime.
7. phi(n) repeats periodically. if n = 6 then '1' 2 3 4 '5' 6 | '7' 8 9 10 '11' 12 | '13' 14 15 …
*/

// In O(sqrt(x))
ll euler_totient(ll x) {
    ll ans = x;
    for(ll i = 2; i * i <= x; i++) {
        if(x%i) continue;
        while(x%i==0) x/=i;
        ans = (ans/i)*(i-1LL);
    }
    if(x>1) ans = (ans/x)*(x-1);
    return ans;
}


// We can also pre-calculate it using the same idea as sieve in O(nlogn).

ll phi[N];

void euler_totient() {
    for(int i = 1; i < N; i++) phi[i] = i;
    for(int i = 2; i < N; i++) {
        if(phi[i]==i) {
            for(int j = i; j < N; j+=i) phi[j]-=(phi[j]/i);
        }
    }
}
