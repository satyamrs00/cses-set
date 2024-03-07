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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> d(n, vector<ll> (n, INT_MAX));

    REP(i, 0, m){
        ll a, b, c;
        cin >> a >> b >> c;
        d[a-1][b-1] = min(c, d[a-1][b-1]);
        d[b-1][a-1] = min(c, d[b-1][a-1]);
    }
    REP(i, 0, n){
        d[i][i] = 0;
    }
    REP(k, 0, n){
        REP(i, 0, n){
            REP(j, 0, n){
                if (d[i][k] == INT_MAX || d[k][j] == INT_MAX){

                } else if (d[i][j] == INT_MAX) {
                    d[i][j] = d[i][k] + d[k][j];
                } else {
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
    }

    REP(i, 0, q){
        ll a, b;
        cin >> a >> b;
        cout << (d[a-1][b-1] == INT_MAX ? -1 : d[a-1][b-1])<< '\n';
    }
    return 0;

}

// - initial approach