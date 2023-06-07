#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef set<ll> sl;
typedef multiset<ll> ml;
typedef map<string, ll> msl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define F first 
#define S second
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()

int main() {
    fastio();
    ll a, b; cin >> a >> b;
    vector<vl> ans(a+1, vl (b+1, 0));
    REP(i,1,a+1){
        REP(j,1,b+1){
            ans[i][j] = LLONG_MAX;
            if (i == j){ ans[i][j] = 0; }
            else {
                REP(k, 1, i){
                    ans[i][j] = min(ans[i][j], ans[k][j]+ans[i-k][j]+1);
                }
                REP(k,1,j){
                    ans[i][j] = min(ans[i][j], ans[i][k]+ans[i][j-k]+1);
                }
            }
        }
    }
    cout << ans[a][b];
}

// - initial approach
// multidimensional dp - for every rectangle try cutting it length-wise and breadth wise and store the min in a 2d array
// ac