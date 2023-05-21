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
    ll n; cin >> n;
    vl in;
    vl ot; // 0 indexed
    REP(i,0,n){
        ll t; cin >> t;
        in.PB(t);
        ll cur_i = i-1;
        while(in[cur_i] >= t){
            if (cur_i == -1) break;
            cur_i = ot[cur_i];
        }
        cout << cur_i+1 << ' ';
        ot.PB(cur_i);
    }

}

// - initial approach
// for every ele loop backwards to find nearest smaller no
// tle
// - second approach
// for each ele check if its previous ele is smaller , if not check for the ans ele of that recursively
// ac