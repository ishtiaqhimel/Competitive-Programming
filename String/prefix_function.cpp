///O(n+m)
/*
    source : https://cp-algorithms.web.app/string/prefix-function.html
    
    a b c a b c d
    0 0 0 1 2 3 0 -> Prefix
    a a b a a a b
    0 1 0 1 2 2 3
*/

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
