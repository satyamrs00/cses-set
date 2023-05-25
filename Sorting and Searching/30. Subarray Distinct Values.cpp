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
    ll n=4,k=2;// cin >> n >> k;
    vl a {1,2,1,2};// REP(i,0,n){ cin >> a[i]; }
    mll eles;
    vl at_least (n+1,0);
    at_least[0] = 1;
    ll cur = 0;
    ll ans = 0;
    REP(i,0,n){
        if (!eles.count(a[i])) cur++;
        eles[a[i]]++;
        ans++;

        if (i+1 >= k){
            ans += at_least[k-1];
        } 
        at_least[cur]++;
        REPIT(it,at_least){
            cout << *it<< ' ';
        } cout << "\n";
    }
    cout << ans;
}

// TODO
// - initial approach