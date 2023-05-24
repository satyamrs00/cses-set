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
#define PF push_front
#define POB pop_back
#define POF pop_front
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
    ll n, k; cin >> n >> k;
    vector<pll> v;
    REP(i,0,n){
        pll t; cin >> t.S >> t.F;
        v.PB(t);
    }
    sort(ALL(v));
    multiset<ll> d;
    REP(i,0,k){ d.insert(0); }
    ll ans = 0;
    REP(i,0,n){
        auto it = d.UB(v[i].S);
        if (it != d.begin()){
            it--;
            d.erase(it);
            d.insert(v[i].F);
            ans++;
        }
    }
    cout << ans;
}

// - initial approach
// sort by ending time, use a deque to store availability of each member, assign a new movie to the first available member
// wa
// - second approach
// sort by ending time, use a multiset to store the availability of each member, assign a new movie to the latest available member
// ac

// TIP try not to use custom comparators un-necessarily