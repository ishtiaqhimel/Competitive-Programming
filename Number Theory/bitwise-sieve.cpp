// memory efficient

int marked[N/64 + 2];
vector<int>prime;

#define Set(x) (marked[x/64] |= (1<<((x%64)/2)))
#define Check(x) (marked[x/64] & (1<<((x%64)/2)))

inline bool isPrime(int num) { return (num>1) && (num==2 || ((num&1) && !Check(num))); }

void sieve() {
    for(int i = 3; i * i < N; i+=2) { // didn't check even numbers
        if(Check(i)==0) {
            for(int j = i * i; j < N; j+=(2*i)) {
                Set(j);
            }
        }
    }
  
    prime.push_back(2);
    for(int i = 3; i < N; i+=2) {
        if(isPrime(i)) prime.push_back(i);
    }
}
