///0-based indexing
///p[0][i] is the maximum length of half palindrome around half index i
///p[1][i] is the maximum length of half palindrome around characters i
/*
***Finding All Sub-Palindrome in 'S'***
         O(n)
    a b b a c a b b a
  0 0 2 0 0 0 0 2 0 0 -> even length
    0 0 0 0 4 0 0 0 0 ->  odd length
*/

vector<int>p[2];

void manacher(const string s) {
    int n = s.size();
    p[0] = vector<int>(n+1); ///even len
    p[1] = vector<int>(n);   ///odd len

    for(int z = 0; z < 2; z++) {
        for(int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;
            if(i < r)
                p[z][i] = min(t, p[z][l+t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while((L >= 1) && (R+1 < n) && (s[L-1]==s[R+1]))
                p[z][i]++, L--, R++;
            if(R > r)
                l=L, r=R;
        }
    }
}
