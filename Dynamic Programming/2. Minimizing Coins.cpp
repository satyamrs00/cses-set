#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
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
    ll n,x; cin >> n >> x;
    vl c(n,0); REP(i,0,n){ cin >> c[i]; }
    vl ans (x+1,0);

    REP(i,1,x+1){
        ll t = LLONG_MAX;
        REP(j,0,n){
            if (i-c[j] < 0 || ans[i-c[j]] < 0){ continue; }
            t = min(t,ans[i-c[j]]);
        }
        if (t == LLONG_MAX)
            ans[i] = -1;
        else
            ans[i] = t+1;
    }
    cout << ans[x];
}

// - initial approach
// dp - for each x, ans = min of answers for x - coin for each coin +1
// ac