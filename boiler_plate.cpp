// જય મા ચામુંડા
// AUTHOR : Sahil Anand
/*----------------------------{APPROACHES}----------------------------*/
// ->Simulation / Brute Force ?? (check constraints)
// ->Binary search ?? (Max/Min) ([NNNN|YYYYYYYYYYYYYYY]) ??
// ->Prefix Sum / Suffix Sum ??
// ->Sliding Window ??
// ->Dp / Greedy ??
// ->Bit Manipulation ??
// ->Parity (odd/even) ??
// ->Two pointers ??
// ->stack, set, multiset, map, dequeue, priority_queue ??
// ->DFS / BFS / Any graph algorithm ??
// ->Do answer follows some pattern ??
// ->GOLDEN RULE: READ PROBLEM STATEMENT TWICE ATLEAST !!!!!!!!!!!!!!!!
/*-----------------------------{HEADERS}-----------------------------*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*--------------------------{Optimizations}--------------------------*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
/*------------------------------{MACROS}------------------------------*/
using namespace std;
using namespace __gnu_pbds;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long int
#define ull unsigned long long int
#define countSetBits(z) __builtin_popcountll(z);
#define vll vector<long long int>
#define LL_MAX __LONG_LONG_MAX__
#define LL_MIN -9223372036854775808
#define PI 3.1415926536
#define mod 1000000007
#define INF 1e18
#define nl endl
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define printWithPrecision(i, x) cout << fixed << setprecision(i) << x << nl
/*-------------------------------{FAST I/O}-------------------------------*/
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
/*----------------------------{NON-STANDARD I/O}----------------------------*/
#define not_standard                  \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
/*----------------------------{PBDS/ORDERED_SET}----------------------------*/
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*---------------------------{OPERATOR_OVERLOADS}---------------------------*/
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
/*--------------------------------{MAIN CODE}--------------------------------*/

int main()
{
    FASTIO
    
    return 0;
}
