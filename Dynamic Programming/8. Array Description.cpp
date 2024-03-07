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
#define mod 1000000007
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
    ll n,m; cin >> n >> m;
    vl x(n); REP(i,0,n){ cin >> x[i]; }
    vl ans(n,0);
    ans[0] = 1;
    ll prev_high=x[0], prev_low = x[0];
    REP(i,0,n){
        if (x[i] == 0){
            ll count = 0;
            REP(j,1,m+1){
                if (m >= prev_low-1 && m <= prev_low+1) count++;
            }
            ans[i] = (ans[i] * count)%mod;
        }
    }
    REP(i,0,n) cout << ans[i] << ' ';

}

// - initial approach