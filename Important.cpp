/*----------------------------{APPROACHES}----------------------------*/
// ->Simulation / Brute Force ?? (check constraints)
// ->Binary search ?? (Max/Min) ([NNNN|YYYYYYYYYYYYYYY]) ??
// ->Prefix Sum / Suffix Sum / (1d 2d) ??
// ->Sliding Window / Two pointers ??
// ->Dp / Greedy ??
// ->Bit Manipulation (not only binary) ??
// ->Parity (odd/even) ??
// ->stack, set, multiset, map, dequeue, priority_queue ??
// ->DFS / BFS / Any graph algorithm ??
// ->Do answer follows some pattern ??
// ->GOLDEN RULE: READ PROBLEM STATEMENT TWICE ATLEAST !!!!!!!!!!!!!!!!
/*--------------------Use this functions directly in your code--------------------*/
//prime check
bool isprime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

//Binary Exponentiation: O(logN)
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

//Sieve of Eratosthenes
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

//Prime Factorization
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

//factorial
ll fact[1000001];
void factorial()
{
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
    {
        fact[i] = i * fact[i - 1];
    }
}

//ncr
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

//inv
//a^(m-2) = a^-1 (mod m);
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

//Euler Totient Function
//phi[i] gives the count of number in range [1,i] that are coprime with i
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

//getCount
//res gives total count number between [1-n] that have gcd=d
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

//Extended Eucledian Algorithm
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

//Linear Diophantine Equation
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
bool find_sol(ll a, ll b, ll c, ll x, ll y)
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
//Decimal to binary - Returns a string of number's binary representation
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

//XOR upto 'n'
ll XorUptoN(ll n)
{
    int r = n%4;
    if(r==3) return 0;
    if(r==2) return n+1;
    if(r==1) return 1;
    return n;     
}
/*----------------------------------------POLICY BASED DATA STRUCTURES----------------------------------------*/
/*Ordered Set*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order, order_of_key  ---> These are 2 additional functionality that the set offers generally.
/*
In the 1st parameter you can use any costom datatype also like pair<ll,ll>

In the 3rd parameter you can costomize it by the following ways:-
->"less" will give the set in asscending order
->"greater" will give the set in descending order
->"less_equal" will give the multiset in asscending order

Make sure that the data type inside the 3rd parameter is same as 1st parameter
*/
int main()
{
    pbds A; // declaration

    // Inserting elements - O(logN)
    A.insert(1);
    A.insert(10);
    A.insert(2);
    A.insert(7);
    A.insert(2); // ordered set only contains unique values by default

    // Printing A
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;
    cout << endl;

    // finding kth element - O(logN)
    cout << "0th element: " << *A.find_by_order(0) << endl;
    cout << "1st element: " << *A.find_by_order(1) << endl;
    cout << "2nd element: " << *A.find_by_order(2) << endl;
    cout << "3rd element: " << *A.find_by_order(3) << endl;
    cout << endl;

    // finding number of elements smaller than X - O(logN)
    cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl;   // 2
    cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
    cout << "No. of elems smaller than 1: " << A.order_of_key(1) << endl;   // 0
    cout << endl;

    // lower bound -> Lower Bound of X = first element >= X in the set  - O(logN)
    cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
    cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;
    cout << endl;

    // Upper bound -> Upper Bound of X = first element > X in the set   - O(logN)
    cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
    cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
    cout << endl;

    // // Remove elements - O(logN)
    A.erase(1);
    A.erase(11); // element that is not present is not affected

    // Printing A
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;
}
