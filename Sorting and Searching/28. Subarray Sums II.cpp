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
    vl a(n);
    REP(i,0,n){ cin >> a[i]; }
    mll sums;
    ll cur = 0; ll ans = 0;
    REP(i,0,n){
        cur = cur+a[i];
        if (cur == x){ ans++; }
        ans += sums[cur-x];
        sums[cur]++;
    }
    cout << ans;
}

// - initial approach
// maitain the count of sum of every subarray that starts at 0;loop over and add the count of (sum-x) upto that ele to ans, because we can remove that subarray from the start to get the desired subarray
// ac