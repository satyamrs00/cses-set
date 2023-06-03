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
    ll n; cin >> n;
    vl ans;
    REP(i,0,n+1){
        if (i < 10) { ans.PB(1); continue; }
        ll ic = i;
        ll t = LLONG_MAX;
        while(ic > 0){
            ll ld = ic%10;
            if (ld > 0){
                t = min(t,ans[i-ld]);
            }
            ic /= 10;
        }
        ans.PB(t+1);
    }
    cout << ans[n];
}

// - initial approach
// dp - for each no, ans is equal to min of answers of (no - digit for each digit) +1
// ac