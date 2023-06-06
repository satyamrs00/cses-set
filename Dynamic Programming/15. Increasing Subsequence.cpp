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

bool com(pll a, pll b){
    if (a.F == b.F) return a.S > b.S;
    return a.F < b.F
}
int main() {
    fastio();
    ll n; cin >> n;
    vl x(n); REP(i,0,n){ cin >> x[i]; }
    set<pll> s;
    REP(i,0,n){
        pll tmp = MP(x[i],1);
        REPITR(it,s){
            
        }
        s.insert(tmp);
    }
    cout << (s.rbegin())->F;
}

// - initial approach
// dp - store length and end value of longest subseq ending at each pos in a set of pair
// tle