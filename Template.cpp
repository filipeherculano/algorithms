/**
 * @file Template.cpp
 * @author Filipe Herculano Rocha
 * @date 2018-09-13
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(a) a.begin(),a.end()
#define pb push_back
#define LSOne(S) (S & (-S))
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " <<
#define mp make_pair
#define mt make_tuple
#define x first
#define y second
#define ii pair<int,int>
#define point pair<double,double>
#define maxn 2222
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define BUFF ios::sync_with_stdio(false);cin.tie(0)
// find_by_order(k) = pointer to kth element (0-based)
// order_of_key(x) = how many elements less than x

typedef unsigned long long llu;
typedef long long int ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-6;
const int mod = 1000000007;

using namespace std;
using namespace __gnu_pbds;