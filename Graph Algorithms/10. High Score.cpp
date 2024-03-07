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
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define F first 
#define S second
#define I iterator
#define mod 1000000007
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()
 
int main() {
    fastio();
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> es(m, vector<ll> (3));
    vector<vector<ll>> rag(n, vl(0));
    REP(i, 0, m){
        ll a, b, c;
        cin >> a >> b >> c;
        es[i] = {a-1, b-1, c};
        rag[b-1].push_back(a-1);
    }
 
    vector<ll> d(n, LLONG_MAX);
    vector<bool> inCycle(n, false);
    d[0] = 0;
    REP(i, 0, n+1){
        REP(j, 0, m){
            ll a = 0;
            if (i == n){
                a = d[es[j][1]];
            }
            if (d[es[j][1]] == LLONG_MAX){
                if (d[es[j][0]] == LLONG_MAX){
                    // d[es[j][1]] = LLONG_MAX;
                } else {
                    d[es[j][1]] = d[es[j][0]] + es[j][2];
                }
            } else {
                if (d[es[j][0]] == LLONG_MAX){
                    // d[es[j][1]] = d[es[j][1]];
                } else {
                    d[es[j][1]] = max(d[es[j][1]], d[es[j][0]] + es[j][2]);
                }
            }
            if (i == n && d[es[j][1]] > a){
                inCycle[es[j][1]] = true;
            }
        }
    }

    // for (auto x : inCycle){
    //     cout << x << ' ';
    // } cout << '\n';

    stack<ll> s;
    vector<bool> vis(n, false);
    s.push(n-1);
    vis[n-1] = true;

    while(!s.empty()){
        ll x = s.top(); s.pop();
        if (inCycle[x] && d[x] != LLONG_MAX){
            cout << -1; return 0;
        }
        for (auto k : rag[x]){
            if (!vis[k]){
                vis[k] = true;
                s.push(k);
            }
        }
    }
    
    cout << d[n-1];
}
 
// - initial approach