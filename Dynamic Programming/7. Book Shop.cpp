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

bool c(pll a, pll b){
    if ((ld)a.F/(ld)a.S == (ld)b.F/(ld)b.S) return a.F < b.F;
    return (ld)a.F/(ld)a.S > (ld)b.F/(ld)b.S;
}

int main() {
    fastio();
    ll n,x; cin >> n >> x;
    vl pr (n,0); REP(i,0,n){ cin >> pr[i]; }
    vector<pll> pa_p_pr; REP(i,0,n){ ll t;cin >> t; pa_p_pr.PB(MP(t, pr[i])); }
    sort(ALL(pa_p_pr), c);
    ll ans = 0;
    REP(i,0,n){
        if (pa_p_pr[i].S <= x){
            ans += pa_p_pr[i].F;
            x -= pa_p_pr[i].S;
        }
    }
    cout << ans;
}
// TODO - wrong
// - initial approach
// greedy - sort a array of pair of price and pages by pages/price desc , loop over and count from the first ele
// wa
