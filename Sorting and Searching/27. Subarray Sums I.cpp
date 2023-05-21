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

int main() {
    fastio();
    ll n,x; cin >> n >> x;
    vl v;
    ll curr_sum = 0;
    ll ans = 0;
    deque<ll> d;
    REP(i,0,n){
        ll t; cin >> t;
        d.PB(t);
        curr_sum += t;
        while(curr_sum>=x){
            if (curr_sum == x) ans++;
            curr_sum -= d.front();
            d.pop_front();
        }
    }
    cout << ans;
}

// - initial approach
// maintain a queue and sum for current subarray, at each input , if sum gets greater than req pop from front if it gets equal at some point, ans++
// ac