/*----------------------------------------{TRIES}----------------------------------------*/
class Trie
{
private:
    struct TrieNode
    {
        TrieNode *child[26];
        bool isEnd;
    };
    TrieNode *node;

public:
    Trie()
    {
        node = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *cur = node;
        for (char c : word)
        {
            if (cur->child[c - 'a'] == NULL)
                cur->child[c - 'a'] = new TrieNode();
            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }
    bool search(string word)
    {
        TrieNode *cur = node;
        for (char c : word)
        {
            if (cur->child[c - 'a'] == NULL)
                return false;
            cur = cur->child[c - 'a'];
        }
        if (cur->isEnd == true)
            return true;
        return false;
    }
    bool startsWith(string prefix)
    {
        TrieNode *cur = node;
        for (char c : prefix)
        {
            if (cur->child[c - 'a'] == NULL)
                return false;
            cur = cur->child[c - 'a'];
        }
        return true;
    }
};

/*--------------------------{POLICY BASED DATA STRUCTURES}-----------------------------*/
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

/*----------------------------------{SEGMENT TREES (TUF)}-------------------------------------*/
// this entire code is for summation
int a[100005], seg[4 * 100005];
void build(int ind, int lo, int hi)
{
    if (hi == lo)
    {
        seg[ind] = a[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2 * ind + 1, lo, mid);
    build(2 * ind + 2, mid + 1, hi);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2]; // update accordingly
}
int query(int ind, int lo, int hi, int l, int r)
{
    if (lo >= l && hi <= r)
        return seg[ind];
    if (hi < l || lo > r)
        return 0; // update accordingly
    int mid = (lo + hi) / 2;
    int left = query(2 * ind + 1, lo, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, hi, l, r);
    return left + right; // update accordingly
}
// Below is the code for Lazy Propogation
int lazy[4 * 100005];
void pointUpdate(int ind, int lo, int hi, int node, int val)
{
    if (lo == hi)
        seg[low] += val;
    else
    {
        int mid = (lo + hi) / 2;
        if (node <= mid && mid >= lo)
            pointUpdate(2 * ind + 1, lo, mid, node, val);
        else
            pointUpdate(2 * ind + 2, mid + 1, hi, node, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2]; // update accordingly
    }
}
void rangeUpdate(int ind, int lo, int hi, int l, int r, int val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (hi - lo + 1) * lazy[ind]; // update accordingly
        if (lo != hi)
        {
            lazy[2 * ind + 1] += lazy[ind]; // update accordingly
            lazy[2 * ind + 2] += lazy[ind]; // update accordingly
        }
        lazy[ind] = 0;
    }
    if (r < lo || l > hi || lo > hi)
        return;
    if (lo >= l && hi <= r)
    {
        seg[ind] += (hi - lo + 1) * val; // update accordingly
        if (lo != hi)
        {
            lazy[2 * ind + 1] += lazy[ind]; // update accordingly
            lazy[2 * ind + 2] += lazy[ind]; // update accordingly
        }
        return;
    }
    int mid = (lo + hi) / 2;
    rangeUpdate(2 * ind + 1, lo, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, hi, l, r, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2]; // update accordingly
}
int lazyQuery(int ind, int lo, int hi, int l, int r, int val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (hi - lo + 1) * lazy[ind]; // update accordingly
        if (lo != hi)
        {
            lazy[2 * ind + 1] += lazy[ind]; // update accordingly
            lazy[2 * ind + 2] += lazy[ind]; // update accordingly
        }
        lazy[ind] = 0;
    }
    if (r < lo || l > hi || lo > hi)
        return 0;
    if (lo >= l && hi <= r)
        return seg[ind];
    int mid = (lo + hi) / 2;
    return (lazyQuery(2 * ind + 1, lo, mid, l, r, val) + lazyQuery(2 * ind + 2, mid + 1, hi, l, r, val)); // update accordingly
}
