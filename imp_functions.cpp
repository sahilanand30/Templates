/*----------------------------{APPROACHES}----------------------------*/
// ->Check and analyse constraints carefully
// ->Simulation / Brute Force ??
// ->Binary search ?? (Max/Min) ([NNNN|YYYYYYYYYYYYYYY]) ??
// ->Prefix Sum / Suffix Sum / (1d 2d) ??
// ->Sliding Window / Two pointers (in sorted only) ??
// ->Dp / Greedy ??
// ->Bit Manipulation (not only binary) ??
// ->Parity (odd/even) ??
// ->stack, set, multiset, map, dequeue, priority_queue(k-min/k-max) ??
// ->DFS / BFS(shortest path/minimun operations) / Any graph algorithm ??
// ->In case of circular array, append the duplicate array to original array
// ->Always try to observe patterns/observation in Game Theory specially
// ->Stack and string very common combination
// ->Binary search on window size very common combination
// ->Do answer follows some pattern ??
// ->Always refer bitwise formulas in bitwise equation problems
// ->Never submit blindly, have a look once before submiting
// ->GOLDEN RULE: READ PROBLEM STATEMENT TWICE CAREFULLY !!!!!!!!!!!!!!!!

/*--------------------{Use this functions directly in your code}--------------------*/
// Prime check: O(sqrt(n))
bool isprime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Binary Exponentiation: O(logN)
ll binpow(ll a, ll b, ll M)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

// Sieve of Eratosthenes
vector<bool> isPrime(1000001, true);
void primeSeive()
{
    ll maxN = 1000000;
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (ll j = 2 * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

// Prime Factorization: O(logN)
void primeFact(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll ct = 0;
            while (n % i == 0)
            {
                ct++;
                n = n / i;
            }
            cout << i << " ^ " << ct << endl;
        }
    }
    if (n > 1)
        cout << n << " ^ " << 1 << endl;
}

// factorial: O(n)
ll fact[1000001];
void factorial()
{
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
    {
        fact[i] = i * fact[i - 1];
    }
}

// ncr
ll ncr(ll n, ll r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

// inv
// a^(m-2) = a^-1 (mod m);
ll binpow(ll a, ll b, ll M)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}
ll inv(ll num, ll m)
{
    ll res = binpow(num, m - 2, mod);
    return res;
}

// Euler Totient Function
// phi[i] gives the count of number in range [1,i] that are coprime with i
ll phi[1000001], maxN = 1000000;
void initializePhi(ll maxN)
{
    for (ll i = 1; i <= maxN; i++)
    {
        phi[i] = i;
    }
    for (ll i = 2; i <= maxN; i++)
    {
        if (phi[i] == i)
        {
            for (ll j = i; j <= maxN; j += i)
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
}

// getCount
// res gives total count number between [1-n] that have gcd=d
ll phi[1000001], maxN = 1000000;
void initializePhi(ll maxN)
{
    for (ll i = 1; i <= maxN; i++)
    {
        phi[i] = i;
    }
    for (ll i = 2; i <= maxN; i++)
    {
        if (phi[i] == i)
        {
            for (ll j = i; j <= maxN; j += i)
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
}
ll getcount(ll d, ll num)
{
    return phi[num / d];
}
// ll n;
// cin>>n;
// for(ll i=1;i*i<=n;i++){
//     if(n%i==0){
//         ll d1=i,d2=n/i;
//         res=res+(d1*getcount(d1,n));
//         if(d1!=d2){
//             res=res+(d2*getcount(d2,n));
//         }
//     }
//     cout<<res<<endl;
// }
/*^in main function^*/

// Extended Eucledian Algorithm
ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1, y = x1 - y1 * (a / b);
    return d;
}

// Linear Diophantine Equation
ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1, y = x1 - y1 * (a / b);
    return d;
}
bool find_sol(ll a, ll b, ll c, ll &x, ll &y)
{
    ll xo, yo;
    ll g = gcd(abs(a), abs(b), xo, yo);
    if (c % g != 0)
    {
        return false;
    }
    x = xo * (c / g);
    y = yo * (c / g);
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
}
// Decimal to binary - Returns a string of number's binary representation
string decToBinary(ll n)
{
    string tmp;
    tmp.push_back('0');
    for (ll i = 1 << 30; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            tmp.push_back('1');
        }
        else
        {
            tmp.push_back('0');
        }
    }
    return tmp;
}

// To convert string into integer
int stringToInt(string s)
{
    int ans;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            ans = s[i] - '0';
        }
        else
        {
            ans = (ans * 10) + s[i] - '0';
        }
    }
    return ans;
}

// XOR upto 'n'
ll XorUptoN(ll n)
{
    int r = n % 4;
    if (r == 3)
        return 0;
    if (r == 2)
        return n + 1;
    if (r == 1)
        return 1;
    return n;
}
