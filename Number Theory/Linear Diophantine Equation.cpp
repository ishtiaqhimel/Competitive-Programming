// An LDE is an equation of the general form ax + by = c. We consider several classical problems on these equations - (degenerate case, a = b = 0 & c = 0 or c != 0)

// 1. Finding one solution. Find any solution (this code does not consider the case a=b=0)
bool LDE(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = exgcd(abs(a), abs(b), x0, y0);
    if(c % g) return false;
    x0 *= c / g;
    y0 *= c / g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

// 2. Finding all solutions
/* 
X = X0 + K (b / g) , Y = Y0 - K (a / g) where g = gcd(a, b) 
*/

// 3. Finding number of solutions & the solutions in a given interval
inline ll Floor(ll p, ll q) {return p>0 ? p/q : p/q - !!(p%q);}
inline ll Ceil(ll p, ll q)  {return p<0 ? p/q : p/q + !!(p%q);}
// Number of solutions of Diophantine Eqn : Ax + By = C
// A,B,C,x,y integers and X1 <= x <= X2 and Y1 <= y <= Y2
inline ll solve(ll A,ll B,ll C,ll X1,ll X2,ll Y1,ll Y2) {
    if(A < 0) { A = -A; B = -B; C = -C; }
 
    ll x,y; 
    ll G = exgcd(A,B,x,y);
    if(G && C%G) return 0;
    
    if(A == 0 && B == 0) return (C == 0) ? (X2 - X1 + 1) * (Y2 - Y1 + 1) : 0;
    if(A == 0) return (Y1 <= C/B && C/B <= Y2) ? (X2 - X1 + 1) : 0;
    if(B == 0) return (X1 <= C/A && C/A <= X2) ? (Y2 - Y1 + 1) : 0;
 
    x = x * (C/G);  y = y * (C/G);
 
    ll newX1 = C - B * Y1, newX2 = C - B * Y2;
    if(newX1> newX2) swap(newX1, newX2);
    newX2 = Floor(newX2, A); newX1 = Ceil(newX1, A);
 
    if(X1 > newX2) return 0;
    if(X2 < newX1) return 0;
    X1 = max(X1, newX1); X2 = min(X2, newX2);
 
    ll div = abs(B/G);
    if(x < X1) return (X2 - x) / div - (X1 - 1 - x) / div;
    if(x > X2) return (x - X1) / div - (x - X2 - 1) / div;
    return 1 + (x - X1) / div + (X2 - x) / div;
}

// 4. Finding the solution having a minimum value of x+y
/* 
X + Y = X0 + Y0 + K ((b - a) / g) where g = gcd(a, b)
  If a < b then K must be smallest possible (minus inf)
  If a > b then K must be largest possible (plus inf)
  If a == b then K must be zero. 
*/

