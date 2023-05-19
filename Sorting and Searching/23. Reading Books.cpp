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
#define ALLR(a) a.rbegin(),a.rend()

int main() {
    fastio();
    ll n;
    cin >> n;
    vl v;
    ll sum = 0;
    ll biggest = 0;
    REP(i,0,n){
        ll t;
        cin >> t;
        sum += t;
        biggest = max(biggest,t);
        v.PB(t);
    }
    ll ans = sum;
    if (biggest - (sum-biggest) > 0){
        ans += biggest - (sum-biggest);
    }
    cout << ans;
}

// - initial approach
// one starts at longest book, two at second longest. applied a check if the one finishes first book before two finishes upto last, if yes, ans = sum else ans = sum+time two had to wait
// ac