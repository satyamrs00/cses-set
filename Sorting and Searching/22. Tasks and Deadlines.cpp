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

bool comp(pll a,pll b){
    return a.F < b.F;
}
int main() {
    fastio();
    ll n;
    cin >> n;
    vector<pll> v;
    REP(i,0,n){
        pll t;
        cin >> t.F >> t.S;
        v.PB(t);
    }
    sort(ALL(v), comp);
    ll time = 0, reward = 0;
    REP(i,0,n){
        time += v[i].F;
        reward += v[i].S - time;
    }
    cout << reward;
}

// - initial approach
// sort the tasks by duration and finish the smallest task first 
// ac