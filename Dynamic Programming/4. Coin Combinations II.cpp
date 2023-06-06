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
    vl c (n,0); ll max_c = 0; REP(i,0,n){ cin >> c[i]; max_c = max(max_c, c[i]); }
    sort(ALL(c));
    vector<umll> ans (x+1);
    REP(i,0,n){
        ans[0][c[i]] = 1;
    }
    REP(i,1,x+1){
        REP(j,0,n){
            if (j > 0) ans[i][c[j]] = ans[i][c[j-1]];
            if (i >= c[j]){
                
                ans[i][c[j]] += ans[i-c[j]][c[j]];
            }
        }
    }
    // cout << ans[x][max_c];
    REPIT(it,ans){
        REP(i,0,n){
            cout << (*it)[c[i]] << ' ';
        } cout << "\n";
    }
}
// TODO - incomplete
// - initial approach