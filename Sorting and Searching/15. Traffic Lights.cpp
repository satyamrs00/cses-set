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

bool com(pll a,pll b){
    if (b.S-b.F == a.S-a.F) return a.F < b.F;
    return a.S-a.F < b.S-b.F;
}
int main() {
    fastio();
    ll x,n; cin >> x >> n;
    set<pll,decltype(com)> s(com);
    s.insert(make_pair(0,x));
    REP(i,0,n){
        cout << s.upper_bound(make_pair())
    }
}

// - initial approach